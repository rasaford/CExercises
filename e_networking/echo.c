#include "network_helper_functions.h"
#include <stdio.h>
#include <unistd.h>

int echo_forever() {
    ssize_t bytes_read = -1;
    while (bytes_read != 0) {
        char* buffer = malloc(1024);
        bytes_read = read(STDIN_FILENO, buffer, 1024);
        write(STDOUT_FILENO, buffer, bytes_read);
        free(buffer);
    }
    return bytes_read;
}

int main(int argc, char* argv[]) {
    echo_forever();
    return 0;
}
