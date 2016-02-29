/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Display.h
 * Author: Logan
 *
 * Created on February 28, 2016, 2:39 PM
 */

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
private:
    void clearScreen();
    void firstDraw();
public:
    Display();
    virtual ~Display();
    void screenInit();
    void update();
    int drawUI(int, int, int);
};

#endif /* DISPLAY_H */

