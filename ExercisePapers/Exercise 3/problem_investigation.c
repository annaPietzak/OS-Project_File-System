#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

// thread one runs in this function
void *do_work_one(void *param) {
	int done = 0;
	while (!done) {
		pthread_mutex_lock(&first_mutex);
		if (pthread_mutex_trylock(&second_mutex) == 0) {
			// do some work
			printf("thread1 got both mutex\n");
			pthread_mutex_unlock(&second_mutex);
			done = 1;
		}
		pthread_mutex_unlock(&first_mutex);
//		printf("thread1 mutex unlocked\n");
//		sleep(random()*10000);
	}	
	pthread_exit(0);
}

// thread two runs in this function
void *do_work_two(void *param) {
	int done = 0;
	while (!done) {
		pthread_mutex_lock(&second_mutex);
		if (pthread_mutex_trylock(&first_mutex) == 0) {
			// do some work
			printf("thread2 got both mutex\n");
			pthread_mutex_unlock(&first_mutex);
			done = 1;
		}
		pthread_mutex_unlock(&second_mutex);
//		printf("thread2 mutex unlocked\n");
//		sleep(random()*10000);
	}
	pthread_exit(0);
}

int main() {
	pthread_t id1, id2;
	pthread_create(&id1, 0, do_work_one, NULL);
	pthread_create(&id2, 0, do_work_two, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
}
