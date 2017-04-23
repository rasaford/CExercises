#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MIN(a,b) ((a) < (b) ? a : b)

typedef struct string {
    char *content;
    int str_len;
    int max_len;
} string_t;

int write_All(int fd, string_t data) {
    ssize_t bytes_written = write(fd, data.content, data.str_len);
    return bytes_written;
}


// the simple version of read_all just using the default read() function
string_t read_All(int fd, size_t max_size) {
    char *buffer = malloc(max_size);
    int bytes_read = read(fd, buffer, max_size - 1);
    buffer[max_size] = '\0';
    string_t str;
    str.content = buffer;
    str.str_len = bytes_read;
    str.max_len = max_size;
    return str;
}

// reads all lines from a file up to max_size in blocks of 512 bytes
string_t read_All2(int fd, size_t max_size) {
    char *buffer = malloc(max_size);
    char *block_buffer = malloc(512);
    size_t bytes_read = 0;
    size_t block_read = 0;
    while (bytes_read < max_size && (block_read = read(fd, block_buffer, 512)) != 0) {
        int headroom = MIN(block_read, max_size - bytes_read);
        for (int i = 0; i < headroom; i++) {
            buffer[bytes_read + i] = block_buffer[i];
        }
        bytes_read += headroom;
    }
    free(block_buffer);
    buffer[bytes_read++] = '\0';
    struct string str;
    str.content = buffer;
    str.str_len = bytes_read;
    str.max_len = max_size;
    return str;
}

int main () {
    int fd = open("snake.txt", O_RDONLY);
    int out = open("output.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    string_t data = read_All2(fd, 12345);

    printf("Stirng content: \n%s\nString length: %d , String max_len: %d\n", data.content, data.str_len, data.max_len);
    int bytes_written = write_All(out, data);
    printf("bytes_written: %d\n", bytes_written);

    close(fd);
    close(out);
    free(data.content);
    return 0;
}

