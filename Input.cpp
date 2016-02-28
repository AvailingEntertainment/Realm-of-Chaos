/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <windows.h>

#include "Draw.h"

class Input {
private:
public:
    void getInput(bool waitingInput) {
        while (waitingInput) {
            // Set timer, if no input after X amount of time, then update.
            Draw d;
            if (GetAsyncKeyState('W') != 0) {
                d.movePlayer(-1, 0);
                waitingInput = false;
            }
            if (GetAsyncKeyState('S') != 0) {
                d.movePlayer(1, 0);
                waitingInput = false;
            }
            if (GetAsyncKeyState('A') != 0) {
                d.movePlayer(0, -1);
                waitingInput = false;
            }
            if (GetAsyncKeyState('D') != 0) {
                d.movePlayer(0, 1);
                waitingInput = false;
            }
            if (GetAsyncKeyState(VK_ESCAPE) != 0) {}
                // kill process
        }
        return;
    }
};