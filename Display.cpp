/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "Draw.h"
#include "Input.h"
#include "World.h"

class Display {
private:
    void clearScreen() {
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
    void firstDraw() {        
        drawUI(1);
        draw.draw();
        drawUI(2);
    }
    int drawUI(int i) {
        if (i == 1) {
            std::cout << "\n      Realm of Chaos\n               Made by Logan Cunningham\n\n";
        } else if (i == 2) {
            int a = draw.getPos(1);
            int b = draw.getPos(2);
            std::cout << "\n    Pos: " << a << "/" << b;
            std::cout << "\n\n";
        }
        return 0;
    }
public:
    Draw draw;
    void screenInit(bool fR) {
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
    void update() {
        bool waitingInput = true;
        int keyCode;
        
        Input input;
        input.getInput(waitingInput);
    }
};