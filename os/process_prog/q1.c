// Write a C Program that will create a child process. Then print the process ID & parent process ID both from the child as well as from the parent.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork(); // Create a child process

    if (pid < 0) { // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
    } else { // Parent process
        printf("Parent process: PID = %d, PPID = %d\n", getpid(), getppid());
    }

    return 0;
}