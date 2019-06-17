#include "Display.h"
#include "Map.h"

#include <iostream>

#define _WIN32_WINNT 0x0500
#include <Windows.h>

void Display::display() {

}

void Display::update() {

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

	
}

void Display::drawUI(int step) {

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