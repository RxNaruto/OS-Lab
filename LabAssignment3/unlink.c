#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    
#include <fcntl.h>    
#include <errno.h>     

int main() {
    const char *tempFile = "tempfile.txt";

    int fd = open(tempFile, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("Temporary file '%s' created successfully.\n", tempFile);

    if (close(fd) < 0) {
        perror("Error closing file");
        unlink(tempFile);  
        exit(EXIT_FAILURE);
    }

    if (unlink(tempFile) != 0) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
    printf("Temporary file '%s' deleted successfully.\n", tempFile);

    fd = open(tempFile, O_RDONLY);
    if (fd < 0) {
        if (errno == ENOENT) {
    
            printf("File '%s' does not exist\n", tempFile);
        } else {
            printf("Error opening file");
            exit(EXIT_FAILURE);
        }
    } else {
      
        printf("File '%s' unexpectedly exists.\n", tempFile);
        close(fd);
        exit(EXIT_FAILURE);
    }

    return 0;
}
