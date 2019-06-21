#include "Display.h"
#include "Map.h"

#include <iostream>
#include <fcntl.h>
#include <io.h>

#define _WIN32_WINNT 0x0500
#include <Windows.h>

Display::Display() {}
Display::~Display() {}

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
	HWND hConsole;// = GetConsoleWindow();
	hConsole = GetForegroundWindow();
	COORD coord;
	RECT r, d;

	int width = 720;
	int height = 520;

	GetWindowRect(hConsole, &r);
	GetWindowRect(hDesktop, &d);
	GetStdHandle(STD_OUTPUT_HANDLE);

	// Sets window size
	SetWindowPos(hConsole, NULL, 0, 0, width, height, SWP_SHOWWINDOW);

	// move window to center of the screen
	int consolePosX = ((d.right - d.left) / 2 - width / 2);
	int consolePosY = ((d.bottom - d.top) / 2 - height / 2);
	SetWindowPos(hConsole, HWND_NOTOPMOST, consolePosX, consolePosY, width, height, SWP_SHOWWINDOW || SWP_NOSENDCHANGING);

	SetConsoleTitle("Realm of Chaos");

	/******    Font    ******/
	CONSOLE_FONT_INFOEX cfie;
	cfie.cbSize = sizeof cfie;
	cfie.nFont = 0;
	cfie.dwFontSize.X = 0;
	cfie.dwFontSize.Y = 16;
	cfie.FontFamily = FF_DONTCARE;
	cfie.FontWeight = FW_NORMAL;

	wcscpy_s(cfie.FaceName, L"Calibri");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfie);
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