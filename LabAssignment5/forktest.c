#include<stdio.h>
#include<unistd.h>
int main(){
    fork();
    printf("Now in process %d\n",getpid());
    printf("parent id is %d\n",getppid());
    

    
}

