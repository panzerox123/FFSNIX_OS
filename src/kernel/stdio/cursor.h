#pragma once
#include "io.h"

class CursorController : protected IOAccess
{
private:
    uint_16 cursor_pos;

public:
    CursorController();
    void set_cursor_position(uint_16);
    void set_cursor_position(int, int);
    void get_cursor_position_coords(uint_16 &, uint_16 &);
    uint_16 get_cursor_position(void);
    void enable_cursor(uint_8, uint_8);
    void disable_cursor(void);
};

CursorController cursorController;