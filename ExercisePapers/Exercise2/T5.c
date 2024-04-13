#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
struct process{
	int process_id;
	int arrival_time;
	int execution_time;
	int start_time;
};

void init_processes(struct process *);
void display(struct process *);
void display_average_waiting_time(struct process *);
void schedule_FCFS(struct process *);

int main()
{
	struct process processes[SIZE];	
	init_processes(processes);

	printf("Orignial input (processes)\n");
	display(processes);
	
	schedule_FCFS(processes);
	printf("Execution according to FCFS policy\n");
	display(processes);
	display_average_waiting_time(processes);	

}
void init_processes(struct process * input)
{
	srand(100);
	for(int i=0;i<SIZE;i++)
	{
		input[i].arrival_time = rand()%10;
		input[i].execution_time = rand()%10;
		input[i].process_id= i;
		input[i].start_time=-1;      
	}	
}
void display(struct process * input){
	printf("process<id, arr, exe, start>:");
	for(int i=0;i<SIZE;i++)
	{
		printf("<%d,%d,%d,%d> ",  input[i].process_id,
		 input[i].arrival_time,  input[i].execution_time, input[i].start_time);	
	}
	printf("\n");
}

void schedule_FCFS(struct process * arr)
{
    float current_time = 0;
    float start_time = 0;

    for (int i = 0; i < SIZE; i++) {
        // Calculate start time for current process
        if (current_time < arr[i].arrival_time || i == 0) {
            // No other processes are running currently
            start_time = arr[i].arrival_time;
        } else {
            // Another process is running
            start_time = arr[i].arrival_time + arr[i-1].execution_time;
        }

        // Print process and start time
        printf("Process started at: %f\n", start_time);
    }
}

void schedule_SJF(struct process * arr)
{
        float shortestBurst = arr[0].execution_time;

        // Iterates through the processes and checks, whether execution time is quicker or not
        for (int i = 0; i < SIZE; i++) {
            if (arr[i].execution_time < shortestBurst) {
                shortestBurst = arr[i].execution_time;
                printf("Process with ID %d started on place: %d\n", arr[i].process_id, i);
            }
        }
}

void schedule_LJF(struct process * arr)
{
    float longestBurst = arr[0].execution_time;

    // Iterates through the processes and checks, whether execution time is slower or not
    for (int i = 0; i < SIZE; i++) {
        if (arr[i].execution_time < longestBurst) {
            longestBurst = arr[i].execution_time;
            printf("Process with ID %d started on place: %d\n", arr[i].process_id, i);
        }
    }
}

void display_average_waiting_time(struct process * arr)
{
    float total_waitingTime = 0;

    // Waiting time for a process is start time (starts being used) minus arrival time
    // (it's around but not yet used)
    for (int i = 0; i < SIZE; i++) {
        float completionTime = arr[i].start_time + arr[i].execution_time;
        float waitingTime = completionTime - arr[i].arrival_time - arr[i].execution_time;
        total_waitingTime = total_waitingTime + waitingTime;
    }

    // Devide the waiting time to get the average
    float average_waitingTime = total_waitingTime / SIZE;

	printf("Average waiting time is: %f\n", average_waitingTime);
}
