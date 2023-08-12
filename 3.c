#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";
    mode_t mode = 0644; // Permissions for the created file

    // Create the file using the creat() system call
    int fd = creat(filename, mode);
    if (fd == -1) {
        perror("Error creating the file");
        return 1;
    }

    printf("File created successfully with descriptor: %d\n", fd);

    close(fd); // Close the file descriptor

    return 0;
}
