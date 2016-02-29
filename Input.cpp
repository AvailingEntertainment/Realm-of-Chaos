#include "Input.h"
#include "Draw.h"
#include "main.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::getInput() {
    bool waiting = true;
    // Set timer, if no input after X amount of time, then update.
    while (waiting)
    {
        Draw d;
        if (GetAsyncKeyState('W') != 0)            
            d.movePlayer(-1, 0);
        if (GetAsyncKeyState('S') != 0)
            d.movePlayer(1, 0);
        if (GetAsyncKeyState('A') != 0)
            d.movePlayer(0, -1);
        if (GetAsyncKeyState('D') != 0)
            d.movePlayer(0, 1);
        if (GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            inputCode = KEY_ESC;
            running = false;
        }
        Sleep(100);
        waiting = false;
    }
}
