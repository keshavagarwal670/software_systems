/*
============================================================================
Name : 9.c
Author : Keshav Agarwal
Description : Write a program to print the following information about a given file.
              a. inode
              b. number of hard links
              c. uid 
              d. gid
              e. size
              f. block size
              g. number of blocks
              h. time of last access
              i. time of last modification
              j. time of last change
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int main(int argc,char* argv[]){
     if(argc!=2){
	     printf("Usage: %s sample.txt\n", argv[0]);
	     return 1;
     }

     struct stat filestat;
     if(stat(argv[1],&filestat)==-1){
         perror("error");
	 return 2;

     }

     printf("inode : %lu\n",filestat.st_ino);
     printf(" no. of hard link : %lu\n", filestat.st_nlink);
     printf("uid : %d\n", filestat.st_uid);
     printf(" no. of blocks : %ld\n",filestat.st_blocks);
     printf("time to last access: %s\n",ctime(&filestat.st_atime));

     return 0;

}
