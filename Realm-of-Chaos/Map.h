#pragma once
class Map
{
public:
	Map();
	~Map();
private:
	char gameMap[20][80] = { // [id][y][x] /* Dark Forest (test) */
		"###############################################################################",
		"#   ^^^^^^^^^^^^^^^^^^^^^^^^^^                                                #",
		"#   ^^^^^^^^^^^^^^^^^^^^^^^^^^                                                #",
		"#   ^^^^      66        ^^^^^^                                                #",
		"#   ^^                    ^^^^                                                #",
		"#   ^      66               ^^                                                #",
		"#   ^^^^         666        ^^                                                #",
		"#   ^^^^^                ^^^^^                                                #",
		"#   ^^^^^^            ^^^^^^^^                                                #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"#                                                                             #",
		"###############################################################################"
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

