#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execvp()...\n");

    // Arguments for the "ls" command
    char *args[] = {"ls", "-l", NULL};

    // Replacing current process with "ls" command
    execvp("ls", args);

    // This will only be printed if execvp() fails
    perror("execvp failed");
    return 0;
}
