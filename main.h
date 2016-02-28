/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newfile.h
 * Author: Logan
 *
 * Created on February 27, 2016, 1:02 AM
 */

#ifndef NEWFILE_H
#define NEWFILE_H

class Draw {
private:
    void clearScreen();
public:
    void draw();
    void movePlayer(int, int);
    int getPos(int);
};

class Input {
public:
    void getInput(bool);
};

class Display {
private:
    void clearScreen();
    void firstDraw();
    int drawUI(int);
public:
    void screenInit(bool);
    void update();
};

#endif /* NEWFILE_H */

