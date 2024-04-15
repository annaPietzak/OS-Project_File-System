#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void * doSmth(void* pid){
	printf("thread %lu from process %d\n", pthread_self(),*(int*) pid);
}

int main() {
    // TODO: Fork multiple processes here
    //two processes forked from main process, child processes fork again new processes
    pid_t p1 = fork(); 
    pid_t p2 = fork();
     
    // TODO: Each process with a different number of threads
	if (p1 == 0) {
		pthread_t p1t1, p1t2, p1t3;
		int pid = getpid();
		pthread_create(&p1t1, NULL, doSmth, &pid);
		pthread_create(&p1t2, NULL, doSmth, &pid);
		pthread_create(&p1t3, NULL, doSmth, &pid);
		pthread_join(p1t1, NULL);
		pthread_join(p1t2, NULL);
		pthread_join(p1t3, NULL);
//		printf("this is thread one with PID %d, and threads %d, %d, %d\n", getpid(), (int)p1t1, (int)p1t2, (int)p1t3);
	}
	if (p2 == 0) {
		pthread_t p2t1, p2t2;
		int pid = getpid();
		pthread_create(&p2t1, NULL, doSmth, &pid );
		pthread_create(&p2t2, NULL, doSmth, &pid );
		pthread_join(p2t1, NULL);
		pthread_join(p2t2, NULL);
//		printf("this is thread two with PID %d, and threads %d, %d\n", getpid(), (int)p2t1, (int)p2t2);
	}
    // TODO: Each thread should print the PID and TID
    }
