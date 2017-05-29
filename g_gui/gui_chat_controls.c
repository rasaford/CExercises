#include <stdio.h>
#include "gui.h"

int client_start_cb(Ihandle* self) {
    printf("TODO: start client\n");
    return IUP_DEFAULT;
}

int server_start_cb(Ihandle* self) {
    printf("TODO: start server\n");
    return IUP_DEFAULT;
}

int main() {
    IupOpen(NULL, NULL);

    Ihandle* address = IupText(NULL);
        IupSetAttribute(address, "EXPAND", "HORIZONTAL");
        IupSetAttribute(address, "CUEBANNER", "address URL");
    Ihandle* port = IupText(NULL);
        IupSetAttribute(port, "CUEBANNER", "port Number");
    Ihandle* startClient = IupButton("Start Client", NULL);
        Icallback* client_callback = IupSetCallback(startClient, "ACTION", (Icallback)client_start_cb);
    Ihandle* startServer = IupButton("Start Server", NULL);
        Icallback* server_callback= IupSetCallback(startServer, "ACTION", (Icallback)server_start_cb);
    Ihandle* chat_history = IupMultiLine(NULL);
        IupSetAttribute(chat_history, "MULTILINE", "YES");
        IupSetAttribute(chat_history, "EXPAND", "YES");
        IupSetAttribute(chat_history, "READONLY", "YES");
        IupSetAttribute(chat_history, "WORDWRAP", "YES");

    Ihandle* new_message = IupText(NULL);
        IupSetAttribute(new_message, "EXPAND", "HORIZONTAL");
    Ihandle* send = IupButton("Send", NULL);

    Ihandle* bottom = IupHbox(new_message, send, NULL);
    Ihandle* top = IupHbox(address, port, startClient, startServer, NULL);
    Ihandle* vbox = IupVbox(top, chat_history, bottom, NULL);
    Ihandle* dialog = IupDialog(vbox);
        IupSetAttribute(dialog, "MINSIZE", "300x250");


    IupShow(dialog);
    IupMainLoop();

    IupClose();
    return 0;
}
