#pragma once
class Map
{
public:
	Map();
	~Map();

	wchar_t getMap(int);
	void updateMap();
	void initMap(int);
private:
    wchar_t gameMap[1][25][86] = { // [id][y][x] /* Dark Forest (test) */
		L"#####################################################################################",
		L"#   ^^^^^^^^^^^^^^^^^^^^^^^^^^                                                      #",
		L"#   ^^^^^^^^^^^^^^^^^^^^^^^^^^                                                      #",
		L"#   ^^^^      66        ^^^^^^                          33333333333                 #",
		L"#   ^^                    ^^^^                          33333333333                 #",
		L"#   ^      66               ^^                          33333333333                 #",
		L"#   ^^^^         666        ^^                          33333:33333                 #",
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
		L"#                                                                                   #",
		L"#####################################################################################"
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

