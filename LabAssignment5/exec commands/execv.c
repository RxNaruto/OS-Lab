#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execv()...\n");
    char *args[] = {"/bin/pwd", NULL};
    execv("/bin/pwd", args);
    printf("execv failed");
    return 0;
}
