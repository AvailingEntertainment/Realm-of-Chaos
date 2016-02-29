#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "windows.h"


class Draw
{
public:
    Draw();
    virtual ~Draw();
    void draw();
    void movePlayer(int, int);
    int getPos(int);
    void clearScreen();
private:

};

#endif // DRAW_H
