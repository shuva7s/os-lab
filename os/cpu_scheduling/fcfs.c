#include <stdio.h>

// Structure to represent a process
typedef struct Process {
    int pid;        // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
} Process;

// Function to perform FCFS Scheduling
void fcfs(Process processes[], int n) {
    int i, total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        // Waiting time for current process
        int waiting_time = current_time - processes[i].arrival_time;
        if (waiting_time < 0)
            waiting_time = 0; // If process arrives after current_time

        total_waiting_time += waiting_time;
        total_turnaround_time += waiting_time + processes[i].burst_time;

        // Update current time
        current_time += processes[i].burst_time;
    }

    // Print average waiting time and average turnaround time
    printf("Average waiting time: %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    Process processes[n];

    // Input arrival time and burst time for each process
    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    // Perform FCFS Scheduling
    fcfs(processes, n);

    return 0;
}
