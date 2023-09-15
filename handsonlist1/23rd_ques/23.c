/*
============================================================================
Name : 23.c
Author : Keshav Agarwal
Description : Write a program to create a Zombie state of the running program.
Date: 8th sep, 2023.
============================================================================
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t child_pid = fork();

	// Parent process
	if (child_pid > 0)
		sleep(50);

	// Child process
	else		
		exit(0);

	return 0;
}
