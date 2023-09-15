/*
============================================================================
Name : 30.c
Author : Keshav Agarwal
Description :Write a program to run a script at a specific time using a Daemon process. 
Date: 9th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main() 
{
	time_t rawtime;
	struct tm * timeinfo;
	
	
    int pid = fork();
    if(pid==0) 
    {
    	printf("Child process...\n");
    	printf("Child pid: %d\n",getpid());
    	
    	int session_id=setsid();
    	if (session_id < 0)
        	exit(EXIT_FAILURE);
    	printf("Session id: %d\n", session_id);
    	
    	
    	chdir("/");
    	
    	umask(0);
    	time(&rawtime);
    	timeinfo = localtime(&rawtime);
    	
    	
        int target_hour = 11;
        int target_minute = 45;
    	while(timeinfo->tm_hour<=target_hour && timeinfo->tm_min<target_minute)
    	{
    		sleep(10);
    		time(&rawtime);
    		timeinfo = localtime(&rawtime);
    	}
    	
   
    	if(timeinfo->tm_hour==target_hour && timeinfo->tm_min==target_minute)
    	{
    		printf("Shell Script running...\n");
    		system("sh $HOME/Documents/GitHub/Software_Systems/09_01_Lab19-30/hello.sh");
    
    		printf("Job completed successfully...\n");
    	}
    }
    else
    	printf("Parent process completed its execution\n");
   return 0;
}
