#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>  
#include<sys/types.h> 
#include<dirent.h>

int main(){
    
    int md;
    md = mkdir("delete_me",0777);
    if(md==0){
        printf("Directory created Successful");
    }
    else{
        printf("Directory not created");
    }
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
    printf("Content after removal of directory \n");
    int rd;
    rd = rmdir("delete_me");
    if(rd==0){
        printf("Directory remove successfully");
    }
    else{
        printf("Directory remove unsuccessful");
    }
    dir = opendir(".");

    if (dir == NULL) {
        perror("Failed to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    } 

}