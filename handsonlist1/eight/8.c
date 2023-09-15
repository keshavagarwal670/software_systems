/*
============================================================================
Name : 8.c
Author : Keshav Agarwal
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date: 8th sep, 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s sample.txt\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r"); // Open the file in read-only mode

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024]; // Assuming a maximum line length of 1024 characters

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Print the line
    }

    fclose(file); // Close the file when done

    return 0;
}
