#include "pch.h"
#include "Map.h"
#include "Display.h"

#include <iostream>
#include <fcntl.h>
#include <io.h>


void Map::drawMap() {
	
	Display disp;
	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 86; x++) {
			if (gameMap[y][x] == L'\u2593')
				disp.textColor(WHITE, BLACK);
			else if (gameMap[y][x] == L'\u0467')
				disp.textColor(GREEN, BLACK);
			else if (gameMap[y][x] == '^')
				disp.textColor(GREEN, BLACK);
			else if (gameMap[y][x] == '6')
				disp.textColor(GREEN, BLACK);
			else if (gameMap[y][x] == '7')
				disp.textColor(LIGHTGREEN, BLACK);
			else
				disp.textColor(WHITE, BLACK);

			std::wcout << gameMap[y][x];

			/*switch (gameMap[y][x]) {
			default:
				disp.textColor(WHITE, BLACK);
				std::wcout << gameMap[y][x];
				break;
			case '#':
				gameMap[y][x] = L'\u2588';
				disp.textColor(WHITE, BLACK);
				std::wcout << gameMap[y][x];
				break;
			case '6':
				gameMap[y][x] = L'\u0467';
				disp.textColor(GREEN, BLACK);
				std::wcout << gameMap[y][x];
				break;
			case '^':
				gameMap[y][x] = L'\u0466';
				disp.textColor(GREEN, BLACK);
				std::wcout << gameMap[y][x];
				break;
			case '7':
				gameMap[y][x] = L'\u20B3';
				disp.textColor(LIGHTGREEN, BLACK);
				std::wcout << gameMap[y][x];
				break;
			
			}*/
			//std::wcout << gameMap[y][x];
		}
		std::wcout << "\n";
	}
}

void Map::updateMap() {
	Display disp;
	disp.textColor(GREEN, BLACK);
	std::wcout << "test\n";
	disp.textColor(BLUE, BLACK);
	std::wcout << "test2";
}

/*
	Player Codes
	\u263a = White Smile
	\u263b = Black Smile

	'\u0466' = Tree Large
	'\u0467' = Tree Small
	'\u20b3' = Tree Other
	'\u2591' = Light block
	'\u2592' = Medium block
	'\u2593' = Dark block
	'\u2588' = Full block

	Building Codes

	\u2554 = Top Left
	\u2557 = Top Right
	\u255a = Bottom Left
	\u255d = Bottom Right
	\u2550 = Horizontal
	\u2551 = Vertical

	\u0488 = Magic Blast 1
	\u0489 = Magic Blast 2
	*/


void Map::initMap() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 10; x++) {
			switch (map[y][x]) {

			}
		}
	}


	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 86; x++) {
			switch (gameMap[y][x]) {
				/*  1-0 are builing blocks  */
			/*case '1':break;
			case '!':break;
			case '2':break;
			case '@':break;
			case '3':break;*/
			case '#':
				gameMap[y][x] = L'\u2593';
				break;
			/*case '4':break;
			case '$':break;
			case '5':break;
			case '%':break;*/
			case '6':
				gameMap[y][x] = L'\u0467';
				break;
			case '^':
				gameMap[y][x] = L'\u0466';
				break;
			case '7':
				gameMap[y][x] = L'\u20B3';
				break;
/*			case '&':break;
			case '8':break;
			case '*':break;
			case '9':break;
			case '(':break;
			case '0':break;
			case ')':break;*/
			}
		}
	}

	drawMap();
}

Map::Map()
{
}
Map::~Map()
{
}