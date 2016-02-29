#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "main.h"
#include "Display.h"
//#include "World.h"

bool running = false;
int inputCode;

void init();
void start();
void checkStop();
void stop();

int main(int argc, char** argv)
{
    init();
    
    while (running)
        start();
        
    return 0;
}

void init()
{
    if (running)
        return;
    
    Display disp;
    disp.screenInit();
    running = true;
}

void start()
{
    while(inputCode != 27) {
        //World world;
        Display disp;
        disp.update();
    }
    stop();
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