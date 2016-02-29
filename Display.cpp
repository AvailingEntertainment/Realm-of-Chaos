#include <iostream>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "Draw.h"
#include "Input.h"
#include "World.h"
#include "Display.h"

Display::Display()
{
    //ctor
}

Display::~Display()
{
    //dtor
}

void Display::clearScreen()
{
    DWORD n, size;
    COORD coord = {0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h, &csbi);
    size = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(h, TEXT (' '), size, coord, &n);
    GetConsoleScreenBufferInfo(h, &csbi);
    FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

    SetConsoleCursorPosition(h, coord);
}

void Display::firstDraw()
{
    Draw d;
    drawUI(1);
    d.draw();
    drawUI(2);
}

int Display::drawUI(int i)
{
    Draw d;
    if (i == 1) {
        std::cout << "\n      Realm of Chaos\n               Made by Logan Cunningham\n\n";
    } else if (i == 2) {
        int a = d.getPos(1);
        int b = d.getPos(2);
        std::cout << "\n    Pos: " << a << "/" << b;
        std::cout << "\n\n";
    }
    return 0;
}

void Display::screenInit(bool fR)
{
    HANDLE hStdout;
    COORD coord;
    GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 85;
    coord.Y = 40;
    HWND console = GetConsoleWindow();
    RECT r;

    GetWindowRect(console, &r);
    MoveWindow(console, coord.X, coord.Y, 480, 320, TRUE);

    if (fR)
            firstDraw();
    fR = false;
}
void Display::update()
{
    bool waitingInput = true;
    int keyCode;

    Input input;
    input.getInput(waitingInput);
}
