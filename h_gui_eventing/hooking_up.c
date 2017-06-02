#define _GNU_SOURCE
#include <stdio.h>
#include "gui.h"
#include "network_helper_functions.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

Ihandle* message_field;
Ihandle* chat_history;
Ihandle* address_field;
Ihandle* port_field;
int connection_fd;

int start_server(struct sockaddr_storage *addr_ptr, size_t addr_size) {
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

int connect_to_server(char* addr, char* port)  {
    struct sockaddr_storage address;
    size_t address_size;
    sockaddr_from_str(addr, port, &address, &address_size);
    int sock = socket((&address)->ss_family, SOCK_STREAM, 0);
    if (-1 == connect(sock, (struct sockaddr *)&address, address_size)) {
        perror("connect()");
        close(sock);
        return -1;
    } else {
        printf("connected to %s:%s\n", addr, port);
    }
    return sock;
}

int recieve_message_cb(int connection_fd, short events) {
    printf("TODO: React to new data on network connection\n");
    return IUP_CONTINUE_WATCH;
}

ssize_t send_message(char* message) {
    return write(connection_fd, message, strlen(message));
}

int client_start_cb(Ihandle* self) {
    char* addr = IupGetAttribute(address_field, "VALUE");
    char* port = IupGetAttribute(port_field, "VALUE");
    connection_fd = connect_to_server(addr, port);
    IupLoopAddWatch(connection_fd, POLLIN, recieve_message_cb);
    return IUP_DEFAULT;
}

int server_start_cb(Ihandle* self) {
    printf("TODO: start server\n");
    return IUP_DEFAULT;
}

int send_message_cb(Ihandle* self) {
    char* message = IupGetAttribute(message_field, "VALUE");
    if (strlen(message) != 0)  {
        IupSetStrf(chat_history, "APPEND", "me: %s", message, NULL);
        IupSetAttribute(chat_history, "SCROLLTO", "1000000000,1000000");
        IupSetAttribute(message_field, "VALUE", "");
        // send the message
        send_message(message);
    }
    return IUP_DEFAULT;
}

int enter_press_cb(Ihandle* self, int c) {
    if (c == K_CR) {
        send_message_cb(self);
        return IUP_IGNORE;
    } else {
        return IUP_CONTINUE;
    }
}

int main() {
    IupOpen(NULL, NULL);

    address_field = IupText(NULL);
        IupSetAttribute(address_field, "EXPAND", "HORIZONTAL");
        IupSetAttribute(address_field, "CUEBANNER", "address URL");
    port_field = IupText(NULL);
        IupSetAttribute(port_field, "CUEBANNER", "port Number");
    Ihandle* startClient = IupButton("Start Client", NULL);
        IupSetCallback(startClient, "ACTION", (Icallback)client_start_cb);
    Ihandle* startServer = IupButton("Start Server", NULL);
        IupSetCallback(startServer, "ACTION", (Icallback)server_start_cb);
    chat_history = IupMultiLine(NULL);
        IupSetAttribute(chat_history, "MULTILINE", "YES");
        IupSetAttribute(chat_history, "EXPAND", "YES");
        IupSetAttribute(chat_history, "READONLY", "YES");
        IupSetAttribute(chat_history, "WORDWRAP", "YES");

    message_field = IupText(NULL);
        IupSetAttribute(message_field, "EXPAND", "HORIZONTAL");
        IupSetCallback(message_field, "K_ANY", (Icallback)enter_press_cb);
    Ihandle* send = IupButton("Send", NULL);
        IupSetCallback(send, "ACTION", (Icallback)send_message_cb);

    Ihandle* bottom = IupHbox(message_field, send, NULL);
    Ihandle* top = IupHbox(address_field, port_field, startClient, startServer, NULL);
    Ihandle* vbox = IupVbox(top, chat_history, bottom, NULL);
    Ihandle* dialog = IupDialog(vbox);
        IupSetAttribute(dialog, "MINSIZE", "300x250");

    IupShow(dialog);
    IupMainLoop();

    IupClose();
    return 0;
}
