#include "Input.h"
#include "Draw.h"
#include "main.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::getInput(bool waitingInput) {
        while (waitingInput) {
            // Set timer, if no input after X amount of time, then update.
            Draw d;
            if (GetAsyncKeyState('W') != 0)
            {
                d.movePlayer(-1, 0);
                waitingInput = false;
            }
            if (GetAsyncKeyState('S') != 0)
            {
                d.movePlayer(1, 0);
                waitingInput = false;
            }
            if (GetAsyncKeyState('A') != 0)
            {
                d.movePlayer(0, -1);
                waitingInput = false;
            }
            if (GetAsyncKeyState('D') != 0)
            {
                d.movePlayer(0, 1);
                waitingInput = false;
            }
            if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                inputCode = 27;
                running = false;
            }
        }
        return;
    }
