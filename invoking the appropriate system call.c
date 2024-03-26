#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid, parent_pid;

    // Fork a new process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("Child process created. PID: %d\n", getpid());
        parent_pid = getppid();
        printf("Parent PID: %d\n", parent_pid);
    } else {
        // Parent process
        printf("Parent process. PID: %d\n", getpid());
        parent_pid = getpid();  // Parent's parent is itself in this case
        printf("Parent PID: %d\n", parent_pid);
    }

    return 0;
}
