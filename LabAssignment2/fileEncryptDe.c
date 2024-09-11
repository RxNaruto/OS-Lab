#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void xor_encrypt_decrypt(char *data, ssize_t length, char key) 
{
    for (ssize_t i = 0; i < length; i++) 
    {
        data[i] ^= key;
    }
}

int main() {
    char filename[100];
    char key;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the encryption key (single character): ");
    scanf(" %c", &key);
    int fd = open(filename, O_RDWR);
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        xor_encrypt_decrypt(buffer, bytesRead, key);

        if (lseek(fd, -bytesRead, SEEK_CUR) == -1) {
            perror("Error seeking in file");
            close(fd);
            return 1;
        }

        if (write(fd, buffer, bytesRead) == -1) {
            perror("Error writing to file");
            close(fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
    }

    close(fd); 

    printf("File encryption/decryption completed successfully.\n");

    return 0;
}