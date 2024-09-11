#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main() {
    
    int fd = open("text1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    int inWord = 0;
    int wordCount = 0;

    // Read the file content and count words
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            if (isspace(buffer[i])) {
                if (inWord) {
                    wordCount++;
                    inWord = 0;
                }
            } else {
                inWord = 1;
            }
        }
    }

    // If the last character in the file is part of a word, count it
    if (inWord) {
        wordCount++;
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);  // Close the file

    // Display the word count
    printf("Number of words in the file: %d\n", wordCount);

    return 0;
}
