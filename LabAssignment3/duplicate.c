#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd1 = open("text1.txt",O_WRONLY|O_APPEND);
    if(fd1<0){
        printf("Error opening file");
    }
    int copy_fd = dup(fd1);
   

write(copy_fd,"This will be output to the file named dup.txt\n", 46);
write(fd1,"This will also be output to the file named dup.txt\n", 51);

int fd3 = open("text1.txt", O_RDONLY);
    if (fd3 < 0) {
        printf("Error opening the file\n");
        return 1;
    }

    char buffer[256];
    int bytes_read;
    while ((bytes_read = read(fd3, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; 
        printf("%s", buffer);
    }
    close(fd3);

    return 0;
}

