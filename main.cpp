#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "main.h"

bool running = false;

void init();
void start();
void stop();

class World {
private:
public:
    void worldInit() {
    }
};

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
        
        Display.update();
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

class Input {
private:
public:
    void getInput(bool waitingInput) {
        while (waitingInput) {
            // Set timer, if no input after X amount of time, then update.
            Draw d;
            if (GetAsyncKeyState('W') != 0) {
                d.movePlayer(-1, 0);
                waitingInput = false;
            }
            if (GetAsyncKeyState('S') != 0) {
                d.movePlayer(1, 0);
                waitingInput = false;
            }
            if (GetAsyncKeyState('A') != 0) {
                d.movePlayer(0, -1);
                waitingInput = false;
            }
            if (GetAsyncKeyState('D') != 0) {
                d.movePlayer(0, 1);
                waitingInput = false;
            }
            if (GetAsyncKeyState(VK_ESCAPE) != 0)
                running = false;
            else {
                waitingInput = false;
            }
        }
        return;
    }
};

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

// Main class
int main(int argc, char** argv) {
    init();
    
    while(running) {
        start();
    }
    
    return 0;
}

void init() {
    if (running == true)
        return;
    
    bool firstRun = true;
    Display display;
    display.screenInit(firstRun);
    running = true;
}

void start() {
    Display display;
    World world;
    
    world.worldInit();
    display.update();
}

void stop() {
    running = false;
}

/**
 mapline object
 * 
 * Class mapLine {
 *  void mapLine() {
 *      // later
 *      
 *      
 *  }
 *  
 * };
 
 
 
 */