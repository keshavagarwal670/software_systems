/*
============================================================================
Name : 5.c
Author : Keshav Agarwal
Description : Write a program to create five new files with infinite loop. Execute the program in the background
              and check the file descriptor table at /proc/pid/fd.
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int fd2 = open("f2",O_CREAT);
    int fd3 = open("f3",O_CREAT);
    int fd4 = open("f4",O_CREAT);
    int fd5 = open("f5",O_CREAT);
    int fd6 = open("f6",O_CREAT);
    while(1);
    return 0;
}
