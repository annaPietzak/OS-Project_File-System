#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define SIZE 10000

void swap(int *xp, int *yp);
void sort(int arr[], int size);

// Function prototypes for thread tasks
// TODO: Declare functions for calculating mean and median

double meanValue=0;
double medianValue;

void* mean(void* dataptr) {
	int size = *(((int **)dataptr)[0]);

    int *ptr = ((int **) dataptr)[1];
	meanValue = (ptr[(size/2)-1] + ptr[size/2])/2.0;
	printf("i calculated the mean %f, i have TID %lu\n",meanValue, pthread_self());
}

void *median(void* dataptr) {
	double sum = 0;
	for(int i = 0; i<*(((int **)dataptr)[0]); i++){
		sum += (((int **)dataptr)[1])[i];
	}
	medianValue = sum / *(((int **)dataptr)[0]);
	printf("i calculated the median %f, i have TID %lu\n", medianValue, pthread_self());		
}

int main() {
    int arr[SIZE];
    for(int i = SIZE - 1; i >= 0; i--)
        arr[(SIZE - 1) - i] = i % 2;

    // TODO: Implement your solution here
    // TODO: Create threads for calculating mean and median
    // TODO: Display the result (mean, median)
    // TODO: Print TIDs of involved threads
    int size = SIZE;
	int *ptr[2] = {(int*)&size, arr};	


    pthread_t thread_id1, thread_id2;
//    printf("Mean Value %f\n", meanValue);
    pthread_create(&thread_id1, NULL, mean,ptr);
    pthread_create(&thread_id2, NULL, median, ptr);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("Mean Value is %f\n", meanValue);
	printf("Median Value is %f\n", medianValue);
    exit(0);

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
