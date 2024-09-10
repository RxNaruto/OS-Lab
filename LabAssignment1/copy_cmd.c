#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
   

    int file1 = open("text1.txt", O_RDONLY); 
    if (file1 == -1) {
        printf("Error opening source file");
        return 1;
    }

    int file2 = open("text2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);  
    if (file2 == -1) {
        printf("Error opening/creating destination file");
        close(file2);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(file1, buffer, sizeof(buffer))) > 0) {
        if (write(file1, buffer, bytesRead) != bytesRead) {
            printf("Error writing to destination file");
            close(file1);
            close(file2);
            return 1;
        }
    }

    if (bytesRead == -1) {
        printf("Error reading source file");
    }

    close(file1); 
    close(file2); 

    return 0;
}

