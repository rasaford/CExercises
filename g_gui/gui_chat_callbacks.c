#include <stdio.h>
#include "gui.h"

int client_start_cb(Ihandle* self) {
    printf("TODO: start client\n");
    return IUP_DEFAULT;
}

int client_start_cb(Ihandle* self) {
    printf("TODO: start client\n");
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
        Icallback* server_callback= IupSetCallback(startServer, "ACTION", (Icallback)client_start_cb);

    Ihandle* box = IupHbox(address, port, startClient, startServer, NULL);
    Ihandle* dialog = IupDialog(box);

    IupShow(dialog);
    IupMainLoop();

    IupClose();
    return 0;
}
