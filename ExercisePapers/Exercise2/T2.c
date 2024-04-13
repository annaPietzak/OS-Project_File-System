#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 10000

void swap(int *xp, int *yp);
void sort(int arr[], int size);
float median(int arr[], int size);
float mean(int arr[], int size);

// Function prototypes for thread tasks
void *meanThread(void *param);
void *medianThread(void *param);

int arr[SIZE];
float medianNumb;
float meanNumb;

int main() {
    for (int i = SIZE - 1; i >= 0; i--) {
        arr[(SIZE - 1) - i] = i % 2;
    }

    pthread_t tid_median;
    pthread_t tid_mean;

    pthread_create(&tid_median, NULL, medianThread, NULL);
    pthread_create(&tid_mean, NULL, meanThread, NULL);

    pthread_join(tid_median, NULL);
    pthread_join(tid_mean, NULL);

    // Print the different things
    printf("Mean: %f\n", meanNumb);
    printf("Median: %f\n", medianNumb);

    return 0;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void *medianThread(void *param) {
    medianNumb = median(arr, SIZE);
    printf("Median Thread ID: %lu\n", pthread_self());
    pthread_exit(NULL);
}

float median(int arr[], int size) {
    sort(arr, size);

    if (size % 2 == 0) {
        int middle1 = size / 2 - 1;
        int middle2 = size / 2;
        return (arr[middle1] + arr[middle2]) / 2.0f;
    } else {
        int middle = size / 2;
        return arr[middle];
    }
}

void *meanThread(void *param) {
    meanNumb = mean(arr, SIZE);
    printf("Mean Thread ID: %lu\n", pthread_self());
    pthread_exit(NULL);
}

float mean(int arr[], int size) {
    float temp = 0;
    for (int i = 0; i < size; i++) {
        temp = temp + arr[i];
    }

    float mean = temp / size;

    return mean;
}
