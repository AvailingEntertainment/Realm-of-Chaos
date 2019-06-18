#include "pch.h"
#include "Display.h"
#include "game.h"
#include "Map.h"

#include <iostream>
#include <fcntl.h>
#include <io.h>

#define _WIN32_WINNT 0x0500
#include <Windows.h>

Display::Display(){}
Display::~Display(){}

void Display::display() {

}

void Display::update() {

}

void Display::drawUI(int step) {
	if (step == 1) {
		std::wcout << "\n            ";
		textColor(LIGHTRED, BLACK);
		std::wcout << "Realm of Chaos\n\n";
		for (int z = 0; z < 39; z++)
			std::wcout << " ";
		textColor(CYAN, BLACK);
		std::wcout << "Developed and maintained by: Logan Cunningham.\n";
		textColor(WHITE, BLACK);
	}
	else if (step == 2) {
		//std::wcout << "\n    Pos: " << playerX << "/" << playerY;
		std::wcout << "  (86, 25)\n";
	}
	else if (step == 3) {
		std::wcout << "Item Description: ";
	}
}

void Display::screenInit() {
	HWND hDesktop = GetDesktopWindow();
	HWND hConsole = GetConsoleWindow();
	COORD coord;
	RECT r, d;

	GetWindowRect(hConsole, &r);
	GetWindowRect(hDesktop, &d);
	GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = ((d.right / 2) - 300);
	coord.Y = ((d.bottom / 2) - 160);

	MoveWindow(hConsole, coord.X, coord.Y, 640, 480, TRUE);
	SetConsoleTitle(L"Realm of Chaos");

	// Draw map
	Display::drawUI(1);

	Map map;
	

	
	for (int y = 0; y < 25; y++) {
		std::wcout << y << std::endl;
		//std::wcout << map[y] << std::endl;
	}
	running = true;
}

void Display::clearScreen() {
	DWORD n, size;
	COORD coord = { 0 };
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
	SetConsoleCursorPosition(h, coord);
}

void Display::textColor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_attribute;
	color_attribute = bg;
	color_attribute = _rotl(color_attribute, 4) | fg;
	SetConsoleTextAttribute(hConsole, color_attribute);
}

void Display::setCursorPosition(int y, int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;
	point.X = x - 1;
	point.Y = y - 1;
	SetConsoleCursorPosition(hConsole, point);
}

void Display::hideCursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
}