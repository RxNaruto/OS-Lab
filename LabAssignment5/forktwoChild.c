#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child one runs ls command\n");
        execl("/bin/ls", "ls", NULL);
        return 1;  
    }
    pid2 = fork();
    if (pid2 == 0) {
        printf("Child two runs date command\n");
        execl("/bin/date", "date", NULL);
        return 1; 
    }
    wait(NULL);
    wait(NULL);

    return 0;
}
