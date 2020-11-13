#include "stdio/print.cpp"
#include "drivers/keyboard/IDT.cpp"
#include "stdio/cursor.cpp"
extern const char ascii_logo[];
/*
======= ======= ======  ||X    || ========== X       X
||      ||      ||      || X   ||     ||       X   X
||===   ||===    =====  ||  X  ||     ||         X
||      ||           || ||   X ||     ||       X   X 
||      ||       =====  ||    X|| ========== X       X
*/

void objectIntialiser()
{
    cursorController = CursorController();
    screenOut = ScreenOut();
    idt = IDT();
}

extern "C" void _start()
{
    objectIntialiser();
    screenOut.clrscr();
    screenOut.print(ascii_logo);
    screenOut.print("FFSNIX OS 2020\nhttps://github.com/panzerox123/FFSNIX_OS", FG_LRED | BG_BYELLOW);
    return;
}
