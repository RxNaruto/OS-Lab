#include<stdio.h>
#include<unistd.h>
int main(){
    fork();
    printf("pid is %d\n",getpid());
    printf("parent id is %d\n",getppid());
    exec();
    printf("pid is %d\n",getpid());
    printf("parent id is %d\n",getppid());
}