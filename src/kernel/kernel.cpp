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

bool shift = false;

void Kernel_KB_Handler(uint_8 scan_code, uint_8 _ch)
{
    if (_ch != 0)
        switch (shift)
        {
        case true:
            screenOut.printc(_ch - 32);
            break;
        case false:
            screenOut.printc(_ch);
            break;
        }
    else
        switch (scan_code)
        {
        case 0x39:
            screenOut.printc(' ');
            break;
        case 0x0E:
            cursorController.set_cursor_position(cursorController.get_cursor_position() - 1);
            screenOut.printc(' ');
            cursorController.set_cursor_position(cursorController.get_cursor_position() - 1);
            break;
        case 0x2A:
            shift = true;
            break;
        case 0xAA:
            shift = false;
            break;
        case 0x36:
            shift = true;
            break;
        case 0xB6:
            shift = false;
            break;
        case 0x3A:
            shift = !shift;
            break;
        case 0x1c:
            screenOut.printc('\n');
            break;
        }
}

extern "C" void _start()
{
    objectIntialiser();
    idt.KBHandler = Kernel_KB_Handler;
    screenOut.clrscr();
    screenOut.print(ascii_logo);
    screenOut.print("FFSNIX OS 2020\nhttps://github.com/panzerox123/FFSNIX_OS", FG_LRED | BG_BYELLOW);
    return;
}
