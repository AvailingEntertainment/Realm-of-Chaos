#include "Draw.h"
#include "Display.h"


// map should be loaded from file, handled in World.cpp
char map[5][11] =
{
    "##########",
    "#        :",
    "#        #",
    "#   @    #",
    "##########",
};

Draw::Draw()
{
    int drawUI(int);
    int getPos(int);
}

Draw::~Draw()
{
}

int getPos(int xy);

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

void Draw::draw()
{
    clearScreen();
    Display d;
    d.drawUI(1, 0, 0);
    for (int y = 0; y < 5; y++)
        std::cout << "   " << map[y] << std::endl;
    int x = getPos(1);
    int y = getPos(2);
    d.drawUI(2, x, y);
}

/*
int drawUI(int pass)
{
    if (pass == 1)
    {
        std::cout << "\n      Realm of Chaos\n\n";
    } else if (pass == 2)
    {
        std::cout << "\n    Pos: " << a << "/" << b;
        std::cout << "\n\n";
    } else { return 0; }
}
*/

void Draw::movePlayer(int movey, int movex)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 11; x++)
        {
            switch (map[y][x])
            {
                case '@':
                {
                    switch (map[y+movey][x+movex])
                    {
                        case ' ':
                        {
                            map[y+movey][x+movex] = '@';
                            map[y][x] = ' ';
                            draw();
                        } break;
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
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 11; x++)
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