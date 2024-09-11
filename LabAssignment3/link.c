#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For link() function
#include <errno.h>   // For errno variable

int main() {
    const char *existing_file = "source.txt";
    const char *hard_link_name = "hard_link.txt";

    // Create a hard link
    if (link(existing_file, hard_link_name) != 0) {
        printf("link");
        exit(EXIT_FAILURE);
    }

    printf("Hard link created successfully.\n");

    return 0;
}
