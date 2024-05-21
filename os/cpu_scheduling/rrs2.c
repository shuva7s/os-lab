#include <stdio.h>

// Define a structure to represent a process
typedef struct Process {
    int process_id;         // Process ID
    int arrival_time;       // Arrival time
    int burst_time;         // Burst time
    int remaining_burst;    // Remaining burst time
    int waiting_time;       // Waiting time
    int turnaround_time;    // Turnaround time
} Process;

int main() {
    int num_processes, time_quantum, current_time = 0, remaining_processes, flag = 0, total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &num_processes);
    remaining_processes = num_processes;
    Process processes[num_processes];

    // Input arrival and burst times for each process and initialize process IDs and remaining burst times
    for (int i = 0; i < num_processes; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_burst = processes[i].burst_time;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\n\nProcess\t| Turnaround Time | Waiting Time\n\n");
    int i = 0;
    while (remaining_processes != 0) {
        if (processes[i].remaining_burst <= time_quantum && processes[i].remaining_burst > 0) {
            current_time += processes[i].remaining_burst;
            processes[i].remaining_burst = 0;
            flag = 1;
        } else if (processes[i].remaining_burst > 0) {
            processes[i].remaining_burst -= time_quantum;
            current_time += time_quantum;
        }

        if (processes[i].remaining_burst == 0 && flag == 1) {
            remaining_processes--;
            processes[i].turnaround_time = current_time - processes[i].arrival_time;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
            total_waiting_time += processes[i].waiting_time;
            total_turnaround_time += processes[i].turnaround_time;
            printf("P[%d]\t|\t%d\t|\t%d\n", processes[i].process_id, processes[i].turnaround_time, processes[i].waiting_time);
            flag = 0;
        }

        if (i == num_processes - 1)
            i = 0;
        else if (processes[i + 1].arrival_time <= current_time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average Turnaround Time = %.2f\n", (float)total_turnaround_time / num_processes);

    return 0;
}
