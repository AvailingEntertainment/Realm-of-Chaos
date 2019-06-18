#include "pch.h"
#include "Display.h"
#include "Map.h"

#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <Windows.h>

void gameLoop(Map m) {
	while (running) {
		// do nothing
	}
}

#include <iostream>
#include <Windows.h>

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	Display d;
	d.screenInit();

	Map m;
	m.drawMap();
	//m.updateMap();

	running = true;
	gameLoop(m);
}