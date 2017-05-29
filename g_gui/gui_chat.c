#include <stdio.h>
#include "gui.h"

int main() {
    IupOpen(NULL, NULL);

    Ihandle* address = IupText(NULL);
        IupSetAttribute(address, "EXPAND", "HORIZONTAL");
        IupSetAttribute(address, "CUEBANNER", "address URL");
    Ihandle* port = IupText(NULL);
        IupSetAttribute(port, "CUEBANNER", "port Number");
    Ihandle* startClient = IupButton("Start Client", NULL);
    Ihandle* startServer = IupButton("Start Server", NULL);

    Ihandle* box = IupHbox(address, port, startClient, startServer, NULL);
    Ihandle* dialog = IupDialog(box);

    IupShow(dialog);
    IupMainLoop();

    IupClose();
    return 0;
}
