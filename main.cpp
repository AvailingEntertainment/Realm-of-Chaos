#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "Display.h"
#include "World.h"

bool running = false;

void init();
void start();
void stop();

// Main class
int main(int argc, char** argv) {
    init();
    
    while(running) {
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
    World world;
    
    disp.update();
}

void stop() {
    running = false;
}

/**
 mapline object
 * 
 * Class mapLine {
 *  void mapLine() {
 *      // later
 *      
 *      
 *  }
 *  
 * };
 
 
 
 */