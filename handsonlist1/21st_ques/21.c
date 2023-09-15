/*
============================================================================
Name : 21.c
Author : Keshav Agarwal
Description : Write a program, call fork and print the parent and child process id.
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	
	pid_t child_id = fork();
	if(child_id < 0) {
		printf("Fork failed");
	}
	else if(child_id == 0) {
		printf("\nChild Process: \n");
		printf("Process id:  %d \n", getpid());
		printf("Parent process: %d \n", getppid());
	}
	else {
		printf("\nParent process: \n");
		printf("Parent Process id: %d \n", getpid());
		printf("Child Process id: %d \n", child_id);
	}
}
