#include <stdio.h>

// Structure to represent a process
typedef struct
{
    int pid;
    int arrival_time; // Arrival time
    int burst_time;   // Burst time
} Process;

void sjf(Process processes[], int n)
{
    int current_time = 0, total_waiting_time = 0, total_turnaround_time = 0;

    // Sort the processes based on burst time
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (processes[i].burst_time > processes[j].burst_time)
            {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; ++i)
    {
        int waiting_time;
        int turn_around_time;
        int completion_time;
        // Calculate waiting time for each process
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;
        waiting_time = current_time - processes[i].arrival_time;
        // Calculate completion time for each process
        completion_time = current_time + processes[i].burst_time;
        // Calculate turnaround time for each process
        turn_around_time = completion_time - processes[i].arrival_time;
        // Update total waiting and turnaround times
        total_waiting_time += waiting_time;
        total_turnaround_time += turn_around_time;
        // Update current time after this process finishes
        current_time = completion_time;
        // Print process data
        printf("\nProcess %d data\n", processes[i].pid);
        printf("Waiting time: %dms\n", waiting_time);
        printf("Turnaround time: %dms\n", turn_around_time);
    }

    // Print total and average waiting and turnaround times
    printf("\nTotal Waiting Time: %dms", total_waiting_time);
    printf("\nTotal Turnaround Time: %dms", total_turnaround_time);
    printf("\nAverage Waiting Time: %.2fms", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2fms", (float)total_turnaround_time / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    Process processes[n];

    // Input arrival time and burst time for each process
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1; // Assign process ID
    }

    // Perform SJF Scheduling
    sjf(processes, n);

    return 0;
}
