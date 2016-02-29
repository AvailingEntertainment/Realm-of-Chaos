#include "Draw.h"


// map should be loaded from file, handled in World.cpp
char map[5][21] =
{
    "####################",
    "#                  :",
    "#                  #",
    "#   @              #",
    "####################"
};
static int mapHeight = sizeof map / sizeof map[0];
static int mapWidth = sizeof map[0] / sizeof(char);

Draw::Draw()
{
}

Draw::~Draw()
{
}

void Draw::clearScreen()
{
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

void Draw::drawUI(int pass, int x, int y)
{
    if (pass == 1)
    {
        std::cout << "\n          Realm of Chaos\n\n\n";
    } else if (pass == 2)
    {
        std::cout << "\n    Pos: " << x << "/" << y;
    }
}

void Draw::draw()
{
    Sleep(50);
    clearScreen();
    drawUI(1,0,0);
    for (int y = 0; y < mapHeight; y++)
        std::cout << "   " << map[y] << std::endl;
    int x = getPos(1) - 1;
    int y = ((sizeof map / sizeof map[0]) - getPos(2)) - 1;
    drawUI(2,x,y);
    Sleep(50);
}

void Draw::movePlayer(int movey, int movex)
{
    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            switch (map[y][x])
            {
                case '@':
                {
                    switch (map[y+movey][x+movex])
                    {
                        case ' ':
                        {
                            map[y][x] = ' ';
                            y=y+movey;
                            x=x+movex;
                            map[y][x] = '@';
                            //map[y+movey][x+movex] = '@';
                            //map[y][x] = ' ';
                            draw();
                            break;
                        }
                        case ':':
                        {   
                            // Move maps
                        } break;
                    }
                } break;
            }
        }
    }
}
int Draw::getPos(int xy)
{
    int px, py;
    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            switch (map[y][x])
            {
                case '@':
                {
                    px = x;
                    py = y;
                }   break;
            }
        }
    }

    if (xy == 1)
    {
        return px;
    } else if (xy == 2)
    {
        return py;
    }

    return 0;
}