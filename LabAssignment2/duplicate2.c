#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd1 = open("tricky.txt",O_WRONLY|O_APPEND|O_CREAT);
    if(fd1<0){
        printf("Error opening file");
    }
    dup2(fd1,1);
    printf("hello this is tricky");
    close(fd1);
    int fd2 = open("tricky.txt", O_RDONLY,0777);
    if (fd2 < 0) {
        printf("Error opening the file\n");
        return 1;
    }

    char buffer[256];
    int bytes_read;
    while ((bytes_read = read(fd2, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; 
        printf("%s", buffer);
    }
    close(fd2);

    return 0;
}

