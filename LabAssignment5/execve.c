#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execve()...\n");

    // Arguments for the "printenv" command
    char *args[] = {"printenv", "MYVAR", NULL};

    // Custom environment variables
    char *envp[] = {"MYVAR=HelloWorld", NULL};

    // Replacing current process with "printenv" command
    execve("/usr/bin/printenv", args, envp);

    // This will only be printed if execve() fails
    perror("execve failed");
    return 0;
}
