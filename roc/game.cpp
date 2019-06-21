#include "game.h"
#include "Display.h"
#include "Map.h"

#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <chrono>
#include <thread>
#define _WIN32_WINNT 0x0500
#include <Windows.h>


void catchInput()
{
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD events;
	INPUT_RECORD buffer;
	ReadConsoleInput(handle, &buffer, 1, &events);

	KEY_EVENT_RECORD ker;

	ker = buffer.Event.KeyEvent;

	switch (ker.wVirtualKeyCode)
	{
	case 'a':
		std::wcout << "a";
		break;
	case 'b':
		std::wcout << "b";
		break;
	}

	if (GetAsyncKeyState(VK_ESCAPE) != 0)
	{
		running = false;
	}
}

void gameLoop(Map map) {
	while (running)
	{
		std::thread test([]() {
			//start tick timer
			std::this_thread::sleep_for(std::chrono::milliseconds(32)); // 30fps
			catchInput();
			//ai update
			});

		// refresh the screen only if something has moved
		if (needsUpdate)
			map.updateMap();
		
		test.join(); // wait for the thread to end
	}
	// if no input/ai change then dont redraw
}

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	// display initialization
	Display d;
	d.screenInit();

	// map initialization
	Map map;
	map.initMap();
	
	// Start game loop
	running = true;
	gameLoop(map);

	return 0;
}

