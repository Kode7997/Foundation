#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child_process_1() {
    printf("Child 1: Started\n");
    // Simulate work in child process 1
    sleep(2); 
    printf("Child 1: Finished\n");
    exit(0);
}

void child_process_2() {
    printf("Child 2: Started\n");
    // Simulate work in child process 2
    sleep(3); 
    printf("Child 2: Finished\n");
    exit(0);
}

int main() {
    pid_t pid1, pid2;

    // Create first child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed for child 1");
        return 1;
    } else if (pid1 == 0) {
        // Code executed by the first child process
        child_process_1();
    }

    // Create second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed for child 2");
        return 1;
    } else if (pid2 == 0) {
        // Code executed by the second child process
        child_process_2();
    }

    // Parent process continues its work
    printf("Parent: Continuing its work\n");

    // Optionally, wait for child processes to finish
    wait(NULL);
    wait(NULL);

    printf("Parent: All child processes have finished\n");

    return 0;
}
