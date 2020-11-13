#include "stdio/print.cpp"
extern const char ascii_logo[];
/*
======= ======= ======  ||X    || ========== X       X
||      ||      ||      || X   ||     ||       X   X
||===   ||===    =====  ||  X  ||     ||         X
||      ||           || ||   X ||     ||       X   X 
||      ||       =====  ||    X|| ========== X       X
*/

extern "C" void _start()
{
    screenOut.clrscr();
    screenOut.print(ascii_logo);
    screenOut.print("FFSNIX OS 2020\nhttps://github.com/panzerox123/FFSNIX_OS", FG_LRED | BG_BYELLOW);
    return;
}