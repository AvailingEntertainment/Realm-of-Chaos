#include "pch.h"
#include "game.h"
#include "Display.h"

#include <iostream>
#include <Windows.h>

int main()
{
	Display d;
	d.screenInit();


}

void gameLoop() {
	while (running)
	{
		if (GetAsyncKeyState(VK_ESCAPE) != 0)
			running = false;
		// tick
	}
}