#include <iostream>
#include <string>
#include <ctime>
#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "headers.h"

/*
 Algorigthm for drawing maps from file.
 * 
 * read file
 * 178 178 178 178 178
 * 178 32 32 32 178
 * 178 32 32 32 178
 * 178 32 32 32 178
 * 178 178 178 178 178
 
 * 
 * only read the numbers. spaces mean next character. uses ascii
 * 
 
 */

int pause() {
    std::cin.ignore(1, '\n');
    return std::cin.get();
}
int main() {
    initializeScreen();
    initializeMap();
    checkSaveGame();
    
    gameLoop();
    
    return 0;
}

void inventory() {
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 55; x++) {
            switch(inv[y][x]) {
                case '#': inv[y][x] = 178; break;
                case ',': inv[y][x] = 'X'; inv[y][x+1] = '\\'; break;
            }
            
        }
    }
    for (int y = 0; y < 13; y++) {
        setCursorPosition(16 + y, 33); 
        for (int x = 0; x < 55; x++) {
            std::cout << inv[y][x];
        }
    }
    setCursorPosition(34, 60);
    std::cout << "InMenu: " << inMenu;
    
    Sleep(300);
    menu = "inv";
    menuHighlight();
    
    while (inMenu) {        
        if (GetAsyncKeyState('W') != 0) {
            if (menuOptionSelected > 1) {
                menuOptionSelected--;
                menuHighlight();
            }
            Sleep(125);
        }
        if (GetAsyncKeyState('S') != 0) {
            if (menuOptionSelected < 11) {
                menuOptionSelected++;
                menuHighlight();
            }
            Sleep(125);
        }
                
        if ((GetAsyncKeyState(VK_TAB) != 0) || (GetAsyncKeyState('B')) ||
            (GetAsyncKeyState(VK_ESCAPE) != 0)) {
            reDraw();
            inMenu = false;
        }
    }
}
void pauseMenu() {
}
void menuHighlight() {
    if (menu == "inv") {
        // Clear previous selection
        if (menuMultiplier != 0) {
            setCursorPosition(menuMultiplier, 35);
            textColor(WHITE, BLACK);
            for (int x = 2; x < 54; x++) {
                std::cout << inv[menuMultiplier-16][x];
            }
        }
        
        // Get new selection
        menuMultiplier = 17 + menuOptionSelected;
            
        setCursorPosition(menuMultiplier, 35);
        textColor(LIGHTGREEN, BLACK);
        
        for (int x = 2; x < 54; x++) {
            std::cout << inv[menuMultiplier-16][x];
        }
    }
    
    hideCursor();
    textColor(WHITE, BLACK);
}

void initializeScreen() {
    HWND hDesktop = GetDesktopWindow();
    HWND hConsole = GetConsoleWindow();
    COORD coord;
    RECT r,d;
    
    GetWindowRect(hConsole, &r);
    GetWindowRect(hDesktop, &d);
    GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = ((d.right / 2) - 300);
    coord.Y = ((d.bottom / 2) - 160);
    
    MoveWindow(hConsole, coord.X, coord.Y, 640, 480, TRUE);
    SetConsoleTitle("World of Warcraft");
    initStep1 = true;
}
void initializeMap() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 86; x++) {
            switch(map[y][x]) {
                case '#':
                    map[y][x] = 219;
                    break;
                case '9':
                    map[y][x] = 232;
                    break;
            }
        }
    }
    drawMap();
    initStep3 = true;
}
void checkSaveGame() {
    initStep3 = true;
}

void gameLoop() {
    if (initStep1 == true || initStep2 == true || initStep3 == true) running = true;
        
    while (running) {
        //tick(); // Every half second game updates, mobs move, etc, etc
        awaitingInput = true;
        getInput();
        hideCursor();
        
        Sleep(125);
    }
}

void getInput() {
    while (awaitingInput) {
        if (GetAsyncKeyState('W') != 0) {
            if (map[pY-1][pX] == ' ') {
                setCursorPosition(pY+5, pX+4);
                std::cout << map[pY][pX];

                ppY = pY; pY--;
                setCursorPosition(pY+5, pX+4);
                std::cout << PLAYER;
            }
            
            awaitingInput = false;
            Sleep(10);
        }
        if (GetAsyncKeyState('S') != 0) {
            if (map[pY+1][pX] == ' ') {
                setCursorPosition(pY+5, pX+4);
                std::cout << map[pY][pX];

                ppY = pY; pY++;
                setCursorPosition(pY+5, pX+4);
                std::cout << PLAYER;
            }
            
            awaitingInput = false;
            Sleep(10);
        }
        if (GetAsyncKeyState('A') != 0) {
            if (map[pY][pX-1] == ' ') {
                setCursorPosition(pY+5, pX+4);
                std::cout << map[pY][pX];

                ppX = pX; pX--;
                setCursorPosition(pY+5, pX+4);
                std::cout << PLAYER;
            }
            
            awaitingInput = false;
        }
        if (GetAsyncKeyState('D') != 0) {
            if (map[pY][pX+1] == ' ') {
                setCursorPosition(pY+5, pX+4);
                std::cout << map[pY][pX];

                ppX = pX; pX++;
                setCursorPosition(pY+5, pX+4);
                std::cout << PLAYER;
            }
            
            awaitingInput = false;
        }
        
        if ((GetAsyncKeyState(VK_TAB) != 0) || (GetAsyncKeyState('B') != 0)) { 
            inMenu = true;
            //testMenu();
            inventory();
            awaitingInput = false;
        }
        if (GetAsyncKeyState(VK_ESCAPE) != 0) {
            running = false;
            awaitingInput = false;
        }
    }
    
    updateScreen();
    hideCursor();
    checkPosition();
}
void checkPosition() { // Broken aswell.. WHY!?!?!?!
    if (map[pY][pX] != ' ') {
        setCursorPosition(pY+5, pX+4);
        std::cout << map[pY][pX];
        setCursorPosition(ppY+5, ppX+4);
        std::cout << PLAYER;
    }
}

void playerInventory() {
    
    
}

void updateScreen() {
    setCursorPosition(30, 8);
    std::cout << "\n    Pos: " << pX << "/" << pY << " ";
    hideCursor();
}
void drawMap() {
    clearScreen();
    textColor(WHITE, BLACK);
    setCursorPosition(1,1);
    drawUI(1);
    
    for (int y = 0; y < 25; y++) {
        std::cout << "   ";
        for (int x = 0; x < 86; x++) {
            if (y == pY && x == pX) {
                std::cout << PLAYER;
            } else {
                std::cout << map[y][x];
            }
        }
        std::cout << std::endl;
    }
    
    drawUI(2);
    std::cout << "\n\n\n";
    hideCursor();
}
void reDraw() {
    clearScreen();
    drawMap();
    hideCursor();
}
void clearScreen() {
    DWORD n, size;
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
void drawUI(int uiPass) {
    if (uiPass == 1) {
        std::cout << "\n          ";
        textColor(LIGHTRED, BLACK);
        std::cout << "Realm of Chaos\n\n";
        for (int lon = 0; lon < 39; lon++)
            std::cout << " ";
        textColor(CYAN, BLACK);
        std::cout << "Developed and maintained by: Logan Cunningham.\n";
        textColor(WHITE, BLACK);
    } else if (uiPass == 2) {
	std::cout << "\n    Pos: " << pX << "/" << pY;
	std::cout << "  (86,25)" << std::endl;
    } else if (uiPass == 3) {
        std::cout << "Item Description: ";
    }
}
void textColor(int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int color_attribute;
    color_attribute = bg;
    color_attribute = _rotl(color_attribute, 4) | fg;
    SetConsoleTextAttribute(hConsole, color_attribute);
}
void setCursorPosition(int y, int x) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point;
    point.X = x - 1;
    point.Y = y - 1;
    SetConsoleCursorPosition(hConsole, point);
}
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
}