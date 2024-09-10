#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    ssize_t bytesRead;
    char buffer[BUFFER_SIZE];

    fd = open("text1.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
            printf("Error writing to console");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        printf("Error reading file");
    }

    close(fd);
    
    return 0;
}

