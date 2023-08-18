#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char* args[]){
   if(argc!=2){
       printf("invalid number of arguments");     
   }
   int fd = open(args[1], O_CREAT|O_EXCL);
   if(fd == -1){
     printf("file already exists");
   }
   else{
     printf("new file created");
   }


   
   return 0;
}

