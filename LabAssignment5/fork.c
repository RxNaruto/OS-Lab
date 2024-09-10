#include<stdio.h>
#include<unistd.h>
int main(){
    int cnt = 0;
    int pid;
    for(cnt=0;cnt<3;cnt++){
        pid = fork();
        printf("Now in process %d\n",getpid());
        printf("Parent id is %d\n",getppid());
        printf("--------\n");
    }
}