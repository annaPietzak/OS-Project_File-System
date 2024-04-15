#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<pthread.h> 
#define SIZE 10000
#define NUM_THREADS 5
int result;
pthread_mutex_t lock;

struct args
{
	int *arr;
	int start;
	int end;
};

void * accumulate(void * in)
{
	//TODO implement accumlate
	int sum;
	for (int i = ((struct args*)in)->start; i < ((struct args*)in)->end; i++) {
		sum = sum + ((struct args*)in)->arr[i];
	}
//	printf("start %d, end %d, sum %d\n", ((struct args*)in)->start, ((struct args*)in)->end, sum);
	pthread_mutex_lock(&lock);
	result += sum;
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main ()
{

	result=0;
        int arr[SIZE];    
        for(int i=0;i<SIZE;i++)
		arr[i]=1;

	
	pthread_t threads[NUM_THREADS-1];
	struct args thread_args[NUM_THREADS-1];
	
	// TODO create a team of thread, each thread must take SIZE/NUM_THREADS to accumulate
	for (int i = 0; i < NUM_THREADS-1; i++) {
		thread_args[i].arr = arr;
		thread_args[i].start = ((double)SIZE/(NUM_THREADS))*i;
		thread_args[i].end = ((double)SIZE/(NUM_THREADS))*(i+1);
//		printf("start %d, end %d\n", thread_args[i].start, thread_args[i].end);
		pthread_create(&threads[i], NULL, accumulate, &thread_args[i]);
	}
	// TODO use struct args to pass arguments to the accumulate function  
	// TODO main thread must participate in the calculation
	
	int sum;
	for (int i = (SIZE/NUM_THREADS)*(NUM_THREADS-1);i < SIZE; i++) {
		sum += arr[i];
	}
	result += sum;
	// TODO make sure all threads finised
	for (int i = 0; i < NUM_THREADS-1; i++){
		pthread_join(threads[i], NULL);
	}
	
	printf("sum  is %d\n", result);
}

