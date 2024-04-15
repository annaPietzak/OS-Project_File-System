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
void schedule_SJF(struct process *);
void schedule_LJF(struct process *);

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

	schedule_SJF(processes);
	printf("Execution according to SJF policy\n");
	display(processes);
	display_average_waiting_time(processes);	

	schedule_LJF(processes);
	printf("Execution accroding to LJF policy\n");	
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
	//TODO
	//sort by arrival time
	for (int i = 0; i < SIZE; i++) {
		struct process tmp = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j].arrival_time  > tmp.arrival_time) {
			arr[j+1] = arr[j];
			j--;
		}	
		arr[j+1] = tmp;
	}

	//set start time based on arrival and execution time
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		arr[i].start_time = sum;
		sum += arr[i].execution_time;
	}
	
}
void schedule_SJF(struct process * arr)
{
        //TODO
//        printf("Not implemented Yet!\n");
		//sort based on execution time, shortest first
		for (int i = 0; i < SIZE; i++) {
				struct process tmp = arr[i];
				int j = i-1;
				while (j >= 0 && arr[j].execution_time  > tmp.execution_time) {
					arr[j+1] = arr[j];
					j--;
				}	
				arr[j+1] = tmp;
		}

		//set start time based on arrival and execution time
		int sum = 0;
		for (int i = 0; i < SIZE; i++) {
			arr[i].start_time = sum;
			sum += arr[i].execution_time;
		}		
}
void schedule_LJF(struct process * arr)
{
        //TODO
        //sort by execution time, longest first
       	for (int i = 0; i < SIZE; i++) {
       		struct process tmp = arr[i];
       		int j = i-1;
       		while (j >= 0 && arr[j].execution_time  < tmp.execution_time) {
       			arr[j+1] = arr[j];
       			j--;
       		}	
       		arr[j+1] = tmp;
       	}
       
       	//set start time based on arrival and execution time
       	int sum = 0;
       	for (int i = 0; i < SIZE; i++) {
       		arr[i].start_time = sum;
       		sum += arr[i].execution_time;
       	}
       	
}
void display_average_waiting_time(struct process * arr)
{
	//TODO
	//sum up all start times
	double avgWT = 0;
	for (int i = 0; i < SIZE; i++) {
		avgWT += arr[i].start_time;
	}
	//divide by number of processes
	avgWT = avgWT / SIZE;
	printf("the average waiting time is %f\n", avgWT);
}
