#define _GNU_SOURCE
#include "network_helper_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <poll.h>


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

int establish_connection(struct sockaddr_storage *addr_ptr, size_t addr_size) {
    int fd = socket(addr_ptr->ss_family, SOCK_STREAM, 0);
    if (-1 == connect(fd, (struct sockaddr *)addr_ptr, addr_size)) {
        perror("connect()");
        close(fd);
        return -1;
    }
    return fd;
}

int client_or_server(char* args[]) {
    struct sockaddr_storage address;
    size_t address_size;
    sockaddr_from_str(args[1], args[2], &address, &address_size);
    int connection_fd = -1;
    if (strcmp(args[3], "server") == 0) {
        connection_fd = wait_connection(&address, address_size);
    } else if (strcmp(args[3], "client") == 0) {
        connection_fd = establish_connection(&address, address_size);
    } else {
        printf("the third argument either has to be \"server\" or \"client\"");
    }
    return connection_fd;
}

int main(int argc, char* argv[]) {
    // argc contains the number of elements of argv
    if (argc < 4) {
        printf("usage: ./chat address port server|client\n");
        return 1;
    }
    int connection_fd = client_or_server(argv);
    if (connection_fd == -1) { return connection_fd; }
    printf("connection established\n");
    struct pollfd events[2];
    events[0].fd = STDIN_FILENO;
    events[0].events = POLLIN;
    events[1].fd = connection_fd;
    events[1].events = POLLIN;
    while (1) {
        poll(events, 2, -1);
        if (events[0].revents & POLLIN) {
            interface(STDIN_FILENO, connection_fd);
        } else if (events[1].revents & POLLIN) {
            interface(connection_fd, STDOUT_FILENO);
        }
    }
    return 0;
}
