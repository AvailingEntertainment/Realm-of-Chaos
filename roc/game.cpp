#include "game.h"
#include "Display.h"
#include "Map.h"

#include <iostream>
#include <fcntl.h>
#include <io.h>


void gameLoop() {
	while (running) {

	}

}

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	Display d;
	d.screenInit();

	Map map;
	map.initMap();
	
	running = true;
	gameLoop();

	return 0;
}