#include "stdio/print.cpp"
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
    screenOut.print("======= ======= ======  ||X    || ========== X       X\n||      ||      ||      || X   ||     ||       X   X\n||===   ||===    =====  ||  X  ||     ||         X\n||      ||           || ||   X ||     ||       X   X\n||      ||       =====  ||    X|| ========== X       X\n");
    screenOut.print("FFSNIX OS 2020\nhttps://github.com/panzerox123/FFSNIX_OS", FG_LRED | BG_BYELLOW);
    return;
}