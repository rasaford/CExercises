#define _GNU_SOURCE
#include "network_helper_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int interface(int read_fd, int write_fd) {
    char buffer[1024];
    ssize_t bytes_read = read(read_fd, buffer, 1024);
    if (bytes_read == 0) {
        return -1;
    }
    write(write_fd, buffer, bytes_read);
    return bytes_read;
}

int wait_connection(struct sockaddr_storage *addr_ptr, size_t addr_size) {
    int fd = socket(addr_ptr->ss_family, SOCK_STREAM, 0);
    if (-1 == fd) {
        perror("socket()");
        return -1;
    }
    if (-1 == bind(fd, (struct sockaddr *)addr_ptr, addr_size)) {
        perror("bind()");
        close(fd);
        return -1;
    }
    printf("listening for incoming connections...\n");
    if (-1 == listen(fd, 3)) {
        perror("listen()");
        close(fd);
        return -1;
    }
    int connection_fd = accept(fd, NULL, NULL);
    if (-1 == connection_fd) {
        perror("accept()");
        close(fd);
        return -1;
    }
    close(fd);
    return connection_fd;
}

int main(int argc, char* argv[]) {
    // argc contains the number of elements of argv
    if (argc < 3) {
        printf("usage: ./chat address port\n");
        return 1;
    }
    // convert the given arguments
    struct sockaddr_storage address;
    size_t address_size;
    sockaddr_from_str(argv[1], argv[2], &address, &address_size);
    int connection_fd = wait_connection(&address, address_size);
    if (connection_fd == -1) {
        return -1;
    }
    printf("connection established\n");
    while (1) {
        interface(STDIN_FILENO, connection_fd);
        interface(connection_fd, STDOUT_FILENO);
    }
    return 0;
}
