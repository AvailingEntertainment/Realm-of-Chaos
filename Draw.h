/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Draw.h
 * Author: Logan
 *
 * Created on February 28, 2016, 2:45 PM
 */

#ifndef DRAW_H
#define DRAW_H

class Draw {
private:
    void clearScreen();
public:
    void draw();
    void movePlayer(int, int);
    int getPos(int);
};

#endif /* DRAW_H */

