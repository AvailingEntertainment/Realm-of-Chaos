#pragma once
class Map
{
public:
	Map();
	~Map();

	void drawMap();
	void updateMap();
	void initMap();
private:
#define PLAYERU L'\u263a'
#define TREE1U L'\u2191'
#define FULLBLOCK L'\u2593'

	wchar_t gameMap[25][86] = { // [id][y][x] /* Dark Forest (test) */
		L"#####################################################################################",
		L"#   ^^^^^^^^^^^^^^^^^^^^^^^^^^                                                      #",
		L"#   ^^^^^^^^^^^^^^^77777777^^^                                                      #",
		L"#   ^^^^      66        ^^77^^                                                      #",
		L"#   ^^                    ^7^^                                                      #",
		L"#   ^      66               ^^                                                      #",
		L"#   ^^^^         666        ^^                                                      #",
		L"#   ^^^^^                ^^^^^                                                      #",
		L"#   ^^^^^^            ^^^^^^^^                                                      #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#                                                                                   #",
		L"#####################################################################################"
	};
	wchar_t map[4][10] = {
		L"#########",
		L"#       #",
		L"#       #",
		L"#########"
	};
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
};

