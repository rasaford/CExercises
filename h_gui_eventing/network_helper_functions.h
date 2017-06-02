// For getaddrinfo(), freeaddrinfo(), getnameinfo(), NI_MAXHOST and NI_MAXSERV
#define _GNU_SOURCE
#include <sys/socket.h>
#include <netdb.h>
// For memcpy(), malloc() and free()
#include <string.h>
#include <stdlib.h>
// For perror() and fprintf()
#include <stdio.h>

/**
 * Converts strings containing a host address and a port number into a binary socket address.
 * host_str can be an IPv4 address like "127.0.0.1" or an IPv6 address like "::1".
 * port_str is simply a string containing the port number as string, e.g. "12345".
 * The binary socket address is stored in the memory pointed to by addr_ptr.
 * The actual size of the address is stored to the memory pointed to by addr_size_ptr.
 *
 * On success 1 is returned, 0 on failure.
 *
 * Example:
 *
 * 	struct sockaddr_storage addr;
 * 	size_t addr_size;
 * 	int result = sockaddr_from_str("127.0.0.1", "12345", &addr, &addr_size);
 * 	if (result == 0) {
 * 		// failed to convert strings to socket address, print error message and abort
 * 	}
 */
int sockaddr_from_str(const char* host_str, const char* port_str, struct sockaddr_storage* addr_ptr, size_t* addr_size_ptr) {
    struct addrinfo hints = { 0 };
    struct addrinfo* results = NULL;
    hints.ai_family = AF_UNSPEC;
    int error = getaddrinfo(host_str, port_str, &hints, &results);
    if (error != 0) {
        if (error == EAI_SYSTEM)
            perror("getnameinfo() failed");
        else
            fprintf(stderr, "getnameinfo() failed: %s\n", gai_strerror(error));
        return 0;
    } else {
        memcpy(addr_ptr, results->ai_addr, results->ai_addrlen);
        *addr_size_ptr = results->ai_addrlen;
        freeaddrinfo(results);
        return 1;
    }
}

/**
 * Converts a binary socket address into a printable string. The string will be malloc()ed
 * so you have to free() it when you no longer need it.
 *
 * Returns a malloc()ed string on success or NULL on failure.
 *
 * Example:
 *
 * 	struct sockaddr_storage addr;
 * 	size_t addr_size;
 * 	// Fill addr and addr_size with an actual address
 * 	char* addr_str = sockaddr_to_str(&addr, addr_size);
 * 	if (addr_str != NULL) {
 * 		printf("address: %s\n", addr_str);
 * 		free(addr_str);
 * 	}
 */
char* sockaddr_to_str(const struct sockaddr_storage* addr_ptr, size_t addr_size) {
    size_t buffer_size = NI_MAXHOST + NI_MAXSERV;
    char* buffer_ptr = malloc(buffer_size);
    int error = getnameinfo((const struct sockaddr *)addr_ptr, addr_size, buffer_ptr, NI_MAXHOST, buffer_ptr + NI_MAXHOST, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
    if (error != 0) {
        free(buffer_ptr);
        if (error == EAI_SYSTEM)
            perror("getnameinfo() failed");
        else
            fprintf(stderr, "getnameinfo() failed: %s\n", gai_strerror(error));
        return NULL;
    }

    size_t host_len = strlen(buffer_ptr);
    size_t port_len = strlen(buffer_ptr + NI_MAXHOST);
    buffer_ptr[host_len] = ' ';
    memmove(buffer_ptr + host_len + 1, buffer_ptr + NI_MAXHOST, port_len + 1);
    buffer_ptr = realloc(buffer_ptr, host_len + 1 + port_len + 1);

    return buffer_ptr;
}
