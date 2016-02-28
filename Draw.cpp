/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "Display.h"

class Draw {
private:
    char map[5][11] = {
        "##########",
        "#        #",
        "#        #",
        "#   @    #",
        "##########" };
    
    void clearScreen() {
        DWORD n;
        DWORD size;
        COORD coord = {0};
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(h, &csbi);
        size = csbi.dwSize.X * csbi.dwSize.Y;
        
        FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
        GetConsoleScreenBufferInfo(h, &csbi);
        FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
        
        SetConsoleCursorPosition(h, coord);
    }
public:
    void draw() {
        clearScreen();
        for (int y = 0; y < 5; y++) {
            std::cout << "   " << map[y] << std::endl;
        }
        
        Display display;
        display.update();
    }
    void movePlayer(int movey, int movex) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 11; x++) {
                switch (map[y][x]) {
                    case '@': {
                        map[y][x] = ' ';
                        map[y+movey][x+movex] = '@';
                        Sleep(200);
                        draw();
                        /*
                        switch(map[y+movey][x+movex]) {
                            case ' ': {
                                map[y][x] = ' ';
                                map[y+movey][x+movex] = '@';
                                draw();
                            } break;
                        }
                        */
                    } break;
                }
            }
        }
    }
    int getPos(int xy) {
        int px, py;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 11; x++) {
                switch (map[y][x]) {
                    case '@': {
                        px = x;
                        py = y;
                    } break;
                }
            }
        }
        
        if (xy == 1)
            return px;
        if (xy == 2)
            return py;
        
        return 0;
    }
};