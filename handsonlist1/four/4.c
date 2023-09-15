/*
============================================================================
Name : 4.c
Author : Keshav Agarwal
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char* args[]){
    if(argc != 2){
        printf("invalid number of arguments");
    }
    int fd = open(args[1], O_CREAT|O_EXCL);
    if(fd == -1){
       printf("file already exists");

    }
    else printf("new file created");

    return 0;

}

