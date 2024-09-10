#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>  // For stat() function and struct stat
#include <unistd.h>    // For exit() function

int main() {
    const char *filename = "source.txt";  // Hardcoded filename
    struct stat file_stat;

    // Get file status
    if (stat(filename, &file_stat) != 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Print the inode number
    printf("Inode number of '%s': %lu\n", filename, (unsigned long)file_stat.st_ino);

    return 0;
}
