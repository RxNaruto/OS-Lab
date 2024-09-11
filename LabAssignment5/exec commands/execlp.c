#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execlp()...\n");
    execlp("date", "date", NULL);
    printf("execlp failed");
    return 0;
}
