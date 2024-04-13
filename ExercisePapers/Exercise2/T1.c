#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define SIZE 10000
#define SCRATCH_FILE "/shared-file" // Had to change from ./shared-file

void swap(int *xp, int *yp);
void sort(int arr[], int size);

int main() {
    int arr[SIZE];
    struct region *rptr;
    float median;
    float mean;
    for (int i = SIZE - 1; i >= 0; i--) {
        arr[(SIZE - 1) - i] = i % 2;
    }

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process calculates median
        sort(arr, SIZE);
        if (SIZE % 2 == 0) {
            // Array has even number of elements
            int middle1 = SIZE / 2 - 1;
            int middle2 = SIZE / 2;
            median = (arr[middle1] + arr[middle2]) / 2.0f;
        } else {
            // Array has odd number of elements
            int middle = SIZE / 2;
            median = arr[middle];
        }
    } else {
        // Parent process calculates mean
        float temp = 0;
        for (int i = 0; i < SIZE; i++) {
            temp = temp + arr[i];
        }
        mean = temp / SIZE;
        wait(NULL);
    }

    // Open shared memory
    int fd = shm_open(SCRATCH_FILE, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        fprintf(stderr, "shm_open failed");
        return 1;
    }

    // Adjusts the size of a shared file descriptor
    if (ftruncate(fd, sizeof(SIZE)) == -1) {
        fprintf(stderr, "ftruncate failed");
        return 1;
    }

    // Maps the file into the memory
    rptr = mmap(NULL, sizeof(SIZE),
                PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (rptr == MAP_FAILED) {
        fprintf(stderr, "mmap failed");
        return 1;
    }

    // Unmap the shared memory region
    munmap(rptr, sizeof(SIZE));

    // Unlink the file
    shm_unlink(SCRATCH_FILE);

    // Print the different things
    printf("Median = %f, process_id(PID) = %d\n", median, getpid());
    printf("Mean = %f, process_id(PID) = %d\n", mean, getpid());
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
