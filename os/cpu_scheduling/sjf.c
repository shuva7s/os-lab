#include <stdio.h>

// Structure to represent a process
typedef struct {
    int burst_time; // Burst time
    int arrival_time; // Arrival time
} Process;

// Function to perform SJF Scheduling
void sjf(Process processes[], int n) {
    int current_time = 0, total_waiting_time = 0, total_turnaround_time = 0;

    // Process execution loop
    for (int i = 0; i < n; i++) {
        // Finding the shortest job available at current time
        int shortest = -1;
        int shortest_burst = 9999; // Initializing with a large value

        for (int j = 0; j < n; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time < shortest_burst) {
                shortest_burst = processes[j].burst_time;
                shortest = j;
            }
        }

        // If no process is available at current time, move to the next arrival time
        if (shortest == -1) {
            int min_arrival_time = 9999;
            for (int j = 0; j < n; j++) {
                if (processes[j].arrival_time < min_arrival_time) {
                    min_arrival_time = processes[j].arrival_time;
                }
            }
            current_time = min_arrival_time;
            i--; // Process the same iteration again
        } else {
            // Execute the shortest job
            current_time += processes[shortest].burst_time;
            total_turnaround_time += current_time - processes[shortest].arrival_time;
            total_waiting_time += current_time - processes[shortest].arrival_time - processes[shortest].burst_time;
            processes[shortest].burst_time = 9999; // Marking as executed
        }
    }

    // Print average waiting time and average turnaround time
    printf("Average waiting time: %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    Process processes[n];

    // Input arrival time and burst time for each process
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Perform SJF Scheduling
    sjf(processes, n);

    return 0;
}
