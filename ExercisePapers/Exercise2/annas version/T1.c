#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define SIZE 10000
#define SCRATCH_FILE "./shared-file"

void swap(int *xp, int *yp);
void sort(int arr[], int size);

int main() {
    int arr[SIZE];
    for(int i = SIZE - 1; i >= 0; i--) {
        arr[(SIZE - 1) - i] = i % 2;
	}
	sort(arr, SIZE);

    // TODO: Fork another process here
    pid_t p = fork();

	//open shared memory
	int descriptor = shm_open("shm", O_CREAT |  O_RDWR, 0777);
	ftruncate(descriptor, 2048*sizeof(int));
	void* ptr = mmap(0, 2048, PROT_READ | PROT_WRITE, MAP_SHARED, descriptor, 0);

    // TODO: One process should calculate the median
    if (p == 0){ //child process
		// assuming th array is sorted
		double median = (double)(arr[SIZE/2-1] + arr[SIZE/2])/2;
		sprintf(ptr, "The median is %f, from child process with PID %d", median, getpid());
    }

	// TODO: The other process should calculate the mean
    else { //parent process
		double sum;
		for(int i = 0; i<SIZE; i++){
			sum += arr[i];
		}
//		printf("sum: %f\n", sum);
		double mean = sum / SIZE;
        // TODO: Print both calculated results and involved PIDs
		printf("The mean is %f, from parent with PID = %d\n", mean, getpid());
		printf("%s\n", (char*)ptr);
	    shm_unlink("shm");
    }
    // TODO: Use shm_open, ftruncate, mmap, and munmap to communicate over mapped files
    return 0;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
