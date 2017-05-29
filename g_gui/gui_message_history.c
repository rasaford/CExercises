#include <stdio.h>
#include "gui.h"
#include<string.h>

Ihandle* message_field;
Ihandle* chat_history;

int client_start_cb(Ihandle* self) {
    printf("TODO: start client\n");
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

    Ihandle* address = IupText(NULL);
        IupSetAttribute(address, "EXPAND", "HORIZONTAL");
        IupSetAttribute(address, "CUEBANNER", "address URL");
    Ihandle* port = IupText(NULL);
        IupSetAttribute(port, "CUEBANNER", "port Number");
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
    Ihandle* top = IupHbox(address, port, startClient, startServer, NULL);
    Ihandle* vbox = IupVbox(top, chat_history, bottom, NULL);
    Ihandle* dialog = IupDialog(vbox);
        IupSetAttribute(dialog, "MINSIZE", "300x250");

    IupShow(dialog);
    IupMainLoop();

    IupClose();
    return 0;
}
