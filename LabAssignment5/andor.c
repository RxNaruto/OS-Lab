#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        printf("First child process (PID: %d)\n", getpid());
        _exit(0);
    } else {
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0) {
            printf("Second child process (PID: %d)\n", getpid());
            _exit(0);
        } else {
            wait(NULL);
            printf("Both children completed, parent process (PID: %d)\n", getpid());
        }
    }

    return 0;
}