#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(){

  char fd1;
  fd1 = open("text1.txt",O_RDONLY);
  if(fd1==-1){
      printf("Error opening file\n");
      exit(0);
      

}
printf("file opened Successfully\n");
printf("fd1=%d\n",fd1);
  
}
