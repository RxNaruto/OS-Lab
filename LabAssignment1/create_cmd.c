#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {

    char userString[BUFFER_SIZE];
    printf("Enter the string to write into the file: ");
    scanf(" %[^\n]", userString); 
    int fd = open("text4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error creating file");
        return 1;
    }
    ssize_t length = strlen(userString);
    if (write(fd, userString, length) == -1) {
        printf("Error writing to file");
        close(fd);
        return 1;
    }
    close(fd);
    fd = open("text4.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file for reading");
        return 1;
    }
    ssize_t bytesRead;
    while ((bytesRead = read(fd, userString, sizeof(userString))) > 0) {
        write(STDOUT_FILENO, userString, bytesRead);
    }

    if (bytesRead == -1) {
        printf("Error reading file");
    }

    close(fd);

    return 0;
}
