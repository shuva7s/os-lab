#include <stdio.h>

#define MAX_PROCESS 10

// Structure to represent a process
typedef struct {
    int burst_time; // Burst time
    int remaining_time; // Remaining time for execution
} Process;


void roundRobin(Process processes[], int n, int quantum) {
    int i, time = 0, total_waiting_time = 0, total_turnaround_time = 0;

    // Iterate until all processes are done
    while (1) {
        int done = 1;

        // Traverse all processes
        for (i = 0; i < n; i++) {
            // If process still has remaining burst time
            if (processes[i].remaining_time > 0) {
                done = 0; // At least one process is not done yet
                if (processes[i].remaining_time > quantum) {
                    // Process still needs quantum time to complete
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    // Process will finish within this quantum
                    time += processes[i].remaining_time;
                    total_turnaround_time += time;
                    total_waiting_time += time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                }
            }
        }

        // If all processes are done, break the loop
        if (done == 1)
            break;
    }

    // Print average waiting time and average turnaround time
    printf("Average waiting time: %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n, quantum, i;
    Process processes[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    roundRobin(processes, n, quantum);
    return 0;
}
