#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execl()...\n");
    execl("/bin/ls", "ls", "-l", NULL);
    perror("execl failed");
    return 0;
}

