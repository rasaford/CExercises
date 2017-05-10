#include "network_helper_functions.h"
#include <stdio.h>
#include <unistd.h>

int interface(int read_fd, int write_fd) {
    char buffer[1024];
    ssize_t bytes_read = read(read_fd, buffer, sizeof(buffer));
    if (bytes_read == 0) {
        return -1;
    }
    write(write_fd, buffer, bytes_read);
    return bytes_read;
}

int establish_connection(struct sockaddr_storage *addr_ptr, size_t addr_size) {
    int fd = socket(addr_ptr->ss_family, SOCK_STREAM, 0);
    if (-1 == connect(fd, (struct sockaddr *)addr_ptr, addr_size)) {
        perror("connect()");
        close(fd);
        return -1;
    }
    return fd;
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
    int connection_fd = establish_connection(&address, address_size);
    if (connection_fd == -1) {
        return -1;
    }
    printf("connection established\n");
    while (1) {
        interface(STDOUT_FILENO, connection_fd);
        interface(connection_fd, STDOUT_FILENO);
    }
    return 0;
}
