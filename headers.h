#ifndef HEADERS_H
#define HEADERS_H

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128

enum {
    KEY_ESC     = 27,
    ARROW_UP    = 256 + 72,
    ARROW_DOWN  = 256 + 80,
    ARROW_LEFT  = 256 + 75,
    ARROW_RIGHT = 256 + 77,
    KEY_F1      = 256 + 59,
    KEY_F2      = 256 + 60,
    KEY_F3      = 256 + 61,
    KEY_F4      = 256 + 62,
    KEY_F5      = 256 + 63,
    KEY_F6      = 256 + 64,
    KEY_F7      = 256 + 65,
    KEY_F8      = 256 + 66,
    KEY_F9      = 256 + 67,
    KEY_F10     = 256 + 68,
    KEY_F11     = 256 + 69,
    KEY_F12     = 256 + 70,
    TRASH	      = 7,
    COMMON      = 15,
    UNCOMMON    = 10,
    RARE	      = 9,
    EPIC	      = 13,
    LEGENDARY   = 6 };

/* Functions */
    
void initializeScreen();
void initializeMap();
void checkSaveGame();

void gameLoop();

void menuHighlight();
void pauseMenu();
void inventory();

void getInput();
void checkPosition();
void updateScreen();
void drawMap();
void reDraw();
void clearScreen();
void drawUI(int);
void textColor(int, int);
void setCursorPosition(int, int);
void hideCursor();

/* Variables */

bool running = false;
bool initStep1 = false;
bool initStep2 = false;
bool initStep3 = false;

char map[25][86] = {
    "#####################################################################################",
    "#                                                                                   #",
    "#   9                                                                               #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#####################################################################################" };
char inv[14][56] = {
    "######################## INVENTORY ####################",
    "#                                                      ",        
    "# ,   Test Item 1                                      ",
    "# ,   Test Item Number 2                               ",
    "# ,   Another Test Item to put through the machine     ",
    "# ,                                                    ",
    "# ,   Here's another                                   ",
    "# ,                                                    ",
    "# ,                                                    ",
    "# ,                                                    ",
    "# ,                                                    ",
    "# ,                                                    ",
    "# ,                                                    ",};
char PLAYER = 0xE8;
int ppX, ppY, npX, npY; // Player X/Y, Previous Player X/Y, Next Player X/Y
int pX = 4; int pY = 13;
int menuOptionSelected = 1;

int paused = 0;
bool nextPositionOpen = false;
bool awaitingInput = false;
bool inMenu = false;

std::string menu;
int menuMultiplier;

#endif