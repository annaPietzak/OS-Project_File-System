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
    // Cast to the struct type so we can access it
    struct args *args = (struct args *)in;

    // Get the different elements
    int *arr = args->arr;
    int start = args->start;
    int end = args->end;

    // Accumulate elements within the range
    int local_result = 0;
    for (int i = start; i <= end; i++) {
        local_result += arr[i];
    }

    // Create results pointer
    int *result_ptr = malloc(sizeof(int));
    if (result_ptr == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(-1);
    }
    *result_ptr = local_result;

    // Lock result so it can be only accessed by one thread at a time
    pthread_mutex_lock(&lock);
    result += local_result;
    pthread_mutex_unlock(&lock);

    return result_ptr;
}

int main ()
{
	result=0;
    int arr[SIZE];
    for(int i=0;i<SIZE;i++)
		arr[i]=1;

	pthread_t threads[NUM_THREADS-1];
	struct args thread_args[NUM_THREADS-1];
    pthread_mutex_init(&lock, NULL);
    
	// Team of threads are created with a chunk_size of SIZE / NUM_THREADS
    int chunk_size = SIZE / NUM_THREADS;
    for (int j = 0; j < NUM_THREADS; j++) {
        thread_args[j].arr = arr;
        thread_args[j].start = j * chunk_size;
        thread_args[j].end = (j + 1) * chunk_size - 1;
        if (j == NUM_THREADS - 1) {
            thread_args[j].end = SIZE - 1;
        }

        int threadTeam = pthread_create(&threads[j], NULL, accumulate, &thread_args[j]);
        if (threadTeam) {
            printf("ERROR; return code from pthread_create() is %d\n", threadTeam);
            exit(-1);
        }
    }

	// Threads join and accumulate the result
    for (int k = 0; k < NUM_THREADS; k++) {
        void *thread_result;
        pthread_join(threads[k], &thread_result);
        int *partial_sum_ptr = (int *)thread_result;
        result += *partial_sum_ptr;
        free(thread_result);
    }

    pthread_mutex_destroy(&lock);

	printf("sum  is %d\n", result);

    return 0;
}
