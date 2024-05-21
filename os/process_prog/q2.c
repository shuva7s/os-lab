// Write a C program that will create a child process. Then modify the value of a globally defined variable from the child process and print the value of the variable from the parent process.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Global variable
int global_var = 10;

int main() {
    pid_t pid;

    pid = fork(); // Create a child process

    if (pid < 0) { // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        printf("Child process: Modifying global_var...\n");
        global_var = 20; // Modify the value of global_var in the child process
        printf("Child process: global_var = %d\n", global_var);
    } else { // Parent process
        // Wait for the child process to finish
        wait(NULL);
        
        // Print the value of global_var from the parent process
        printf("Parent process: global_var = %d\n", global_var);
    }

    return 0;
}
