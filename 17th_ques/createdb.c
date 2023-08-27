#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
        
       
        int fd_write = open("db", O_WRONLY|O_CREAT);

        if( fd_write==-1)
                printf("Your system is useless\n");

        // Logic
        char ticket_no;
        scanf("%c",&ticket_no);
        
        int write_bytes = write(fd_write, &ticket_no, 1);
        
        int close_fd_write = close(fd_write);

        if(close_fd_write==-1)
                printf("Your system is useless, coz it can't even close a file\n");

        return 0;

}

