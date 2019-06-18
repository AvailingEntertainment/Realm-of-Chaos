#include "Map.h"
#include "pch.h"
#include <stdlib.h>

Map::Map() {}
Map::~Map() {}

void Map::initMap(int id) {
	

	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 86; x++) {
			switch (gameMap[id][y][x]) {
			case '#':
				gameMap[id][y][x] = '\u2593';
				break;
			case '3':
				gameMap[id][y][x] = '\u2588';
				break;
			case '^':
				gameMap[id][y][x] = '\u0466';
				break;
			case '6':
				gameMap[id][y][x] = '\u0467';
				break;

			}
		}
	}
	/*\u263a = White Smile
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
	\u0489 = Magic Blast 2 */
}

wchar_t Map::getMap(int id) {
	wchar_t newMap[1][25][86] = { gameMap[id] };
}