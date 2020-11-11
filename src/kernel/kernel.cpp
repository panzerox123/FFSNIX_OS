#include "stdio/cursor_control.cpp"
#include "stdio/print.cpp"

/*
======= ======= ======  ||X    || ========== X       X
||      ||      ||      || X   ||     ||       X   X
||===   ||===    =====  ||  X  ||     ||         X
||      ||           || ||   X ||     ||       X   X 
||      ||       =====  ||    X|| ========== X       X
*/

extern "C" void _start(){
    clrscr();
    print(
        "======= ======= ======  ||X    || ========== X       X\n||      ||      ||      || X   ||     ||       X   X\n||===   ||===    =====  ||  X  ||     ||         X\n||      ||           || ||   X ||     ||       X   X \n||      ||       =====  ||    X|| ========== X       X\n"
    );
    print("I think this works?");
    return;
}