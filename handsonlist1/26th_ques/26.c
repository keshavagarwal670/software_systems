/*
============================================================================
Name : 26.c
Author : Keshav Agarwal
Description : Write a program to execute an executable program.
              a. use some executable program
              b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 8th sep, 2023.
============================================================================
*/

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    pid_t pid;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s ../sample.txt\n", argv[0]);
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        execl("/usr/bin/cat", "cat", argv[1], NULL);

        perror("execl");
        exit(1);
    } else {
        printf("Parent process is waiting for the child...\n");

        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit normally\n");
        }
    }

    return 0;
}
