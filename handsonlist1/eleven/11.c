/*
============================================================================
Name : 11.c
Author : Keshav Agarwal
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 8th sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char* filename = "output.txt";
    int fd1, fd2, fd3;

    // Open the file for appending
    fd1 = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd1 == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor using dup
    fd2 = dup(fd1);

    // Duplicate the file descriptor using dup2
    fd3 = open("/dev/null", O_WRONLY); // Open a dummy file descriptor
    if (fd3 == -1) {
        perror("Error opening /dev/null");
        close(fd1);
        return 2;
    }
    if (dup2(fd3, fd2) == -1) {
        perror("Error using dup2");
        close(fd1);
        close(fd3);
        return 3;
    }

    // Append data to the file using each descriptor
    const char* data = "Appended data\n";
    write(fd1, data, strlen(data));
    write(fd2, data, strlen(data));
    write(fd3, data, strlen(data));

    // Close the file descriptors
    close(fd1);
    close(fd2);
    close(fd3);

    printf("Data appended successfully to %s using dup, dup2, and fcntl.\n", filename);

    return 0;
}

