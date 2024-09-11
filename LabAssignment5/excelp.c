#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execlp()...\n");

    // Replacing current process with "ls" command without specifying full path
    execlp("ls", "ls", "-l", NULL);

    // This will only be printed if execlp() fails
    perror("execlp failed");
    return 0;
}
