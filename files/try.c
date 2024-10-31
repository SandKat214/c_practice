#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXSIZE 1001

int main()
{
    char file_in[] = "Infile.txt";

    int fd;

    // Trying to open sequential input file
    if ((fd = open(file_in, O_RDONLY)) == -1) {
        printf("File %s could not be opened.\n", file_in);
        return -1;
    }

    if (fchmod(fd, S_IROTH | S_IWOTH | S_IXOTH) == -1) {
        printf("There is an error changing permission of output file %s\n", file_in);
        return -1;
    }

    // Trying to close the sequential output file
    if (close(fd) == -1) {
        printf("There is an error at closing %s\n", file_in);
        return -1;
    }

    if (chmod(file_in, S_IRGRP | S_IWGRP | S_IXGRP) == -1) {
        printf("There is an error changing permissions of output file %s\n", file_in);
        return -1;
    }

    return 0;
}
