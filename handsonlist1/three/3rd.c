/*
============================================================================
Name : 3rd.c
Author : Keshav Agarwal
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
   const char *filename = "example.txt";
   mode_t mode = 0666;

   int fd = creat(filename,mode);
   if(fd == -1){
        perror("file not created");
	return 1;
   }

   printf("file created successfully with descriptor : %d\n",fd);

   close(fd);
   return 0;
}

