#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running execle()...\n");
    char *envp[] = {"MYVAR=HelloWorld", NULL};
    execle("/usr/bin/printenv", "printenv", "MYVAR", NULL, envp);
    printf("execle failed");
    return 0;
}
