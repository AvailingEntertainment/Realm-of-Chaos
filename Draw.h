#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "windows.h"

extern int inMap;

class Draw
{
public:
    Draw();
    virtual ~Draw();
    void drawUI(int pass);
    int getPos(int xy);
    void draw();
    void movePlayer(int, int);
    void clearScreen();
private:
    
};

#endif // DRAW_H
