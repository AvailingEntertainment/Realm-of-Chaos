#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "main.h"
#include "Display.h"
#include "World.h"

bool running = false;
int inputCode;

void init();
void start();
void checkStop();
void stop();

int main(int argc, char** argv) {
    init();
    
    while(running) {
        if (inputCode == 27) {
            stop();
        }
        start();
    }
    
    return 0;
}

void init() {
    if (running == true)
        return;
    
    bool firstRun = true;
    Display disp;
    disp.screenInit(firstRun);
    running = true;
}

void start() {
    Display disp;
    
    disp.update();
}

void stop() {
    system("CLS");
    std::cout << "Ending Game." << std::endl;
    system("PAUSE");
    // Do shutdown tasks here.
    /*
     World world;
     world.shutdownWorld();
     * 
     * something like that.
     * 
     */
    running = false;
}