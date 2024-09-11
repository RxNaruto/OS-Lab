#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execve()...\n");
    char *args[] = {"echo", "$GREETING", NULL};
    char *envp[] = {"GREETING=Hello from execve!", NULL};
    execve("/bin/echo", args, envp);
    printf("execve failed");
    return 0;
}
