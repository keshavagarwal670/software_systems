/*
============================================================================
Name : 19.c
Author : Keshav Agarwal
Description : Create a FIFO file by
              a. mknod command
              b. mkfifo command
              c. use strace command to find out, which command (mknod or mkfifo) is better.
              c. mknod system call
              d. mkfifo library function
Date: 10th oct, 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

    // Using mknod system call
    if (mknod("mknod_fifo", S_IFIFO | 0777, 0) == -1) {
        perror("mknod");
        return 1;
    } else {
        printf("FIFO file created using mknod\n");
    }

    // Using mkfifo library function
    if (mkfifo("mkfifo_fifo", 0777) == -1) {
        perror("mkfifo");
        return 1;
    } else {
        printf("FIFO file created using mkfifo\n");
    }

    return 0;
}
