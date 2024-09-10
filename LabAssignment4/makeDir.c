#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>  
#include<sys/types.h> 

int main(){
    
    int md;
    
    md = mkdir("newdir",0777);
    if(md==0){
        printf("directory Created \n");
    }
    else{
        printf("Directory not created  \n");
    }
    int cd =  chdir("newdir");
    if(cd==0){
        printf("Directory changed successfully  \n");
    }
    else{
        printf("Error changing the directory  \n");
    }
    char buffer[1024]; 

    if (getcwd(buffer, sizeof(buffer)) != NULL) {
        printf("Current working directory: %s\n", buffer);
    } 
    else {
    printf("Failed to get current working directory  \n");
     }
}