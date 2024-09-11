#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
       int fd1,fd2;
       printf("This would create twofiles");
       fd1 = creat("text1.txt",0777);
       fd2 = creat("text2.txt",0777);
}
