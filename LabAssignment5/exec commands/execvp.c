#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execvp()...\n");
    char *args[] = {"whoami", NULL};
    execvp("whoami", args);
    printf("execvp failed");
    return 0;
}
