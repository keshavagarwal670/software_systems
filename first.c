#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Create a soft link (symbolic link)
    const char *sourcePath = "./original";
    const char *softlinkPath = "./softlink";
    if (symlink("original","softlink" ) == -1) {
        perror("Error creating soft link");
        return 1;
    }
    printf("Soft link created: %s -> %s\n", softlinkPath, sourcePath);

    // Create a hard link
    const char *hardlinkPath = "hardlink.txt";
    if (link("original", "hardlink.txt") == -1) {
        perror("Error creating hard link");
        return 1;
    }
    printf("Hard link created: %s -> %s\n", "hardlink.txt", "original");

    // Create a FIFO (named pipe)
    const char *fifoPath = "myfifo";
    if (mkfifo(fifoPath, 0666) == -1) {
        perror("Error creating FIFO");
        return 1;
    }
    printf("FIFO created: %s\n", fifoPath);

    return 0;
}

