#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execv()...\n");

    // Arguments for the "ls" command
    char *args[] = {"/bin/ls", "-l", NULL};

    // Replacing current process with "ls" command
    execv("/bin/ls", args);

    // This will only be printed if execv() fails
    perror("execv failed");
    return 0;
}
