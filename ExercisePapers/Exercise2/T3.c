#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void *printPIDTID(void *param);

int main() {
    // Fork multiple processes
    pid_t pid1 = fork();
    pid_t pid2 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Fork failed of pid1");
        return 1;
    } else if (pid1 == 0) {
        pthread_t tid1_1;
        pthread_create(&tid1_1, NULL, printPIDTID, NULL);

        pthread_t tid1_2;
        pthread_create(&tid1_2, NULL, printPIDTID, NULL);

        pthread_join(tid1_1, NULL);
        pthread_join(tid1_2, NULL);
    } else {
        pthread_t tid1_3;
        pthread_create(&tid1_3, NULL, printPIDTID, NULL);
        pthread_join(tid1_3, NULL);

        wait(NULL);
    }

    if (pid2 < 0) {
        fprintf(stderr, "Fork failed of pid2");
        return 1;
    } else if (pid2 == 0) {
        pthread_t tid2_1;
        pthread_create(&tid2_1, NULL, printPIDTID, NULL);
        pthread_join(tid2_1, NULL);
    } else {
        pthread_t tid2_2;
        pthread_create(&tid2_2, NULL, printPIDTID, NULL);
        pthread_join(tid2_2, NULL);

        wait(NULL);
    }
}

void *printPIDTID(void *param) {
    printf("PID: %d, TID: %lu\n", getpid(), pthread_self());
    pthread_exit(NULL);
}
