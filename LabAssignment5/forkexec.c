#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process (PID: %d) executing 'ps' command...\n", getpid());
        execlp("ps", "ps", NULL); 
        printf("execlp failed");
        return 1;
    }
    else {
        wait(NULL);
        printf("Parent process (PID: %d) continues after child execution.\n", getpid());
    }

    return 0;
}
