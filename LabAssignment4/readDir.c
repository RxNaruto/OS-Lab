#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>  
#include<sys/types.h> 
#include<dirent.h>

int main(){
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL) {
        printf("Failed to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);




}