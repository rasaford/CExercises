#include <stdio.h>
#include "gui.h"

int main() {
    IupOpen(NULL, NULL);

    Ihandle* label = IupLabel("Hello GUI!");
    Ihandle* dialog = IupDialog(label);

    IupShow(dialog);
    IupMainLoop();

    IupClose();
    return 0;
}
