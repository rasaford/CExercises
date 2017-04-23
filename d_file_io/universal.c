#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("input.txt", O_RDONLY);
    int fd2 = open("output.txt", O_WRONLY);
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, 1024);
    // write to STDOUT
    write(2, buffer, bytes_read);
    // write to the target file
    write(fd2, buffer, bytes_read);
    close(fd);
    close(fd2);
    return 0;
}
