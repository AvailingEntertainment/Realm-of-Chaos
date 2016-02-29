#include <iostream>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "Draw.h"
#include "Input.h"
#include "World.h"
#include "Display.h"

Display::Display()
{
}

Display::~Display()
{
}

void Display::screenInit()
{
    HANDLE hStdout;
    HWND hDesktop = GetDesktopWindow();
    HWND hConsole = GetConsoleWindow();
    COORD coord;
    RECT r, d;
    
    GetWindowRect(hConsole, &r);
    GetWindowRect(hDesktop, &d);
    GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = ((d.right / 2) - 300);
    coord.Y = ((d.bottom / 2) - 160);
    
    MoveWindow(hConsole, coord.X, coord.Y, 480, 320, TRUE);
}
void Display::update()
{
    Draw d;
    d.draw();

    Input input;
    input.getInput();
}
