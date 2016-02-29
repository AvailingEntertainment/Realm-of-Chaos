#include "Draw.h"
#include "Display.h"


char map[5][11] =
{
    "##########",
    "#        #",
    "#        #",
    "#   @    #",
    "##########"
};

Draw::Draw()
{
    //ctor
}

Draw::~Draw()
{
    //dtor
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

void Draw::draw()
{
    clearScreen();
    for (int y = 0; y < 5; y++)
        std::cout << "   " << map[y] << std::endl;
}
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
                        case '#':
                        {   
                            
                        } break;
                    }
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
        return px;
    if (xy == 2)
        return py;

    return 0;
}
