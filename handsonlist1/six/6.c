/*
============================================================================
Name : 6.c
Author : Keshav Agarwal
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
   char buffer[3];
   size_t bytesread;

   while(bytesread = (read(STDIN_FILENO,buffer,sizeof(buffer)))>=1){
        write(STDOUT_FILENO,buffer,sizeof(buffer));

   }
   if(bytesread == -1){
        perror("error in reading from stdin");
	return 1;
   }
   return 0;

}
