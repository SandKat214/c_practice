#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE 15

int main(int argc, char *argv[])
{
    char *filename =  "Infile.txt";
    int fd;
    char c;
    char buffer[SIZE+1];
    int r;

    if ((fd = open(filename, O_RDWR | O_CREAT)) == -1) {
        printf("Error opening file\n");
        return 1;
    }

    while ((r = read(fd, buffer, SIZE)) > 0) {
        buffer[r] = '\0';
        printf("%s", buffer);
    }
    printf("\n");

    strcpy(buffer, "\nFffffffffF");
    write(fd, buffer, 11);

    lseek(fd, 22, SEEK_SET);
    strcpy(buffer, "FffffffffF\n");
    write(fd, buffer, 11);


    if (close(fd) == -1) {
        printf("Error closing file\n");
        return 1;
    }

    return 0;
}