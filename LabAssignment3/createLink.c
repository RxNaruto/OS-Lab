#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <unistd.h> 

int main(){
    const char *oldPath ="new.txt";
    const char *newPath ="linkednew.txt";

    if(link(oldPath,newPath)==0){
        printf("Hard link created \n");
    }
    else{
        printf("hard link creation unsuccessful");
    }
    struct stat file_stat1;
    if(stat(oldPath,&file_stat1)!=0){
        printf("Error getting stat of file");
    }
    struct stat file_stat2;
    if(stat(newPath,&file_stat2)!=0){
        printf("Error getting stat of file2");
    }
    printf("Inode number of '%s ': %lu\n",oldPath,(unsigned long)file_stat1.st_ino);
    printf("Inode number of  '%s ': %lu\n",newPath,(unsigned long)file_stat2.st_ino);

}