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

#include <unistd.h>
#include <sys/socket.h>
#include <poll.h>

int wait_for_first_connection(struct sockaddr_storage *bind_addr_ptr, size_t bind_addr_size) {
	// Open a new data stream socket (SOCK_STREAM). We set the first parameter (IPv4 or IPv6)
	// depending on the address. If the address is an IPv4 address (e.g. 192.168.0.1) we want an
	// IPv4 socket, if it's an IPv6 address (e.g. fe80::...) we want an IPv6 socket.
	int server_fd = socket(bind_addr_ptr->ss_family, SOCK_STREAM, 0);
	if (server_fd == -1) {
		perror("socket()");
		return -1;
	}

	// Set the local end of the socket to the specified address. For a server this is the place it will
	// listen on for incoming connections.
	int result = bind(server_fd, (struct sockaddr *)bind_addr_ptr, bind_addr_size);
	if (result == -1) {
		perror("bind()");
		close(server_fd);
		return -1;
	}

	// Tell the socket to listen for new connections. After this call we're open for business. Clients
	// can now connect to us.
	result = listen(server_fd, 3);
	if (result == -1) {
		perror("listen()");
		close(server_fd);
		return -1;
	}

	// Wait for the first client connection and accept it. The result is a new socket that represents the
	// data stream connection to the client.
	int connection_fd = accept(server_fd, NULL, NULL);
	if (connection_fd == -1) {
		perror("accept()");
		close(server_fd);
		return -1;
	}

	// We don't want to listen for any more client connections so close the server socket.
	close(server_fd);

	return connection_fd;
}

int establish_connection_to(struct sockaddr_storage *target_addr_ptr, size_t target_addr_size) {
	// Open a new data stream socket (SOCK_STREAM). We set the first parameter (IPv4 or IPv6)
	// depending on the address. If the address is an IPv4 address (e.g. 192.168.0.1) we want an
	// IPv4 socket, if it's an IPv6 address (e.g. fe80::...) we want an IPv6 socket.
	int connection_fd = socket(target_addr_ptr->ss_family, SOCK_STREAM, 0);
	if (connection_fd == -1) {
		perror("socket()");
		return -1;
	}

	// Connect our socket to the server (hopefully) listening at the target address. After that we
	// should have a data stream connection to the server (or an error thrown into our face).
	int result = connect(connection_fd, (struct sockaddr *)target_addr_ptr, target_addr_size);
	if (result == -1) {
		perror("connect()");
		close(connection_fd);
		return -1;
	}

	return connection_fd;
}



int main(int argc, char* argv[]) {
	// Show a helpfull error message if we didn't get all command line arguments
	if (argc < 4) {
		printf("Missing the host, port or client/server switch command line arguments.\n");
		printf("Usage: %s host port server|client\n", argv[0]);
		return 1;
	}

	// Convert the host and port command line arguments into a binary network address
	struct sockaddr_storage addr;
	size_t addr_size;
	sockaddr_from_str(argv[1], argv[2], &addr, &addr_size);

	// Depending on the last command line argument open a server or connect as a client
	int connection_fd = -1;
	if ( strcmp(argv[3], "server") == 0 ) {
		connection_fd = wait_for_first_connection(&addr, addr_size);
	} else if ( strcmp(argv[3], "client") == 0 ) {
		connection_fd = establish_connection_to(&addr, addr_size);
	} else {
		printf("The 3rd command line argument has to be either \"server\" or \"client\".\n");
		return 1;
	}

	// The buffer for our read/write loop
	char buffer[1024];

	// Run our read/write loop forever (1 is always true as the loop condition). That is until someone inside the
	// loop uses break to exit the loop.
	while(1) {
		// Wait for input from the terminal, read it into buffer and send that data over the network connection.
		// If read() returns 0 the standard input was closed with ctrl+d (we got an end of file). In that case we
		// break out of the loop.
 		ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
 		if (bytes_read == 0)
 			break;
 		write(connection_fd, buffer, bytes_read);

		// Wait for data from the network connection, read it into the buffer and print that data on the terminal
		// If read() returns 0 the network connection was closed with ctrl+d (we got an end of file). In that case we
		// break out of the loop.
 		bytes_read = read(connection_fd, buffer, sizeof(buffer));
 		if (bytes_read == 0)
 			break;
		write(STDOUT_FILENO, buffer, bytes_read);
	}

	return 0;
}
