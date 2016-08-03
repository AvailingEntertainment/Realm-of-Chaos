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

void playerInventory();
void playerStats();

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

int menuOptionSelected = 1;

int paused = 0;
bool nextPositionOpen = false;
bool awaitingInput = false;
bool inMenu = false;

std::string menu;
int menuMultiplier;


/* Player Related Variables*/
char PLAYER = 0xE8;
int ppX, ppY, npX, npY; // Player X/Y, Previous Player X/Y, Next Player X/Y
int pX = 4; int pY = 13;

struct playerSave {
    char playerName[20];
    char playerRace[2];
    char playerClass[2];
    char playerHealth[6];
    char playerMana[6];
    char playerMaxHealth[6];
    char playerMaxMana[6];
    
    char playerXP[20];
    char playerLevel[2];
    char playerStrength[3];
    char playerAgility[3];
    char playerStamina[3];
    char playerIntellect[3];
    char playerSpirit[3];
    char playerDamage[3];
    char playerHit[3];
    
    char playerArmor[4];
    char playerWeapon[4];
    char playerGold[5];
    char playerCoordX[3];
    char playerCoordY[3];
    char playerZoneId[2];
    
    char inventory0[6];
    char inventory1[6];
    char inventory2[6];
    char inventory3[6];
    char inventory4[6];
    char inventory5[6];
    char inventory6[6];
    char inventory7[6];
    char inventory8[6];
    char inventory9[6];
    char inventory10[6];
    char inventory11[6];
    
}savefile;

int race_color[] = {15, 10, 13, 14, 2, 7, 11, 6, 12, 11};
int class_color[] = {7, 15, 11, 14, 13, 5, 1, 2, 6, 4};
int quality_color[] = {8, 15, 10, 9, 13, 6};
char *race_list[] = {
    "Human", "Night Elf", "Gnome", "Dwarf", "Orc", "Undead", "Troll", "Tauren", "Blood Elf", "Draenei", "\n" };

char *class_list[] = {
    "Warrior", "Priest", "Mage", "Rogue", "Paladin", "Warlock", "Shaman", "Hunter", "Druid", "Death Knight", "\n"};

char *title_list[] = {
    "Knight", "Archon", "Wizard", "Assassin", "Crusader", "Necromancer", "Seer", "Ranger", "Warden", "Scourge Knight"};



#endif