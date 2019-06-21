#pragma once

class Player
{
public:
	Player();
	int playerCoord(int);
	void movePlayer(int, int);
private:
	int playerX = 2;
	int playerY = 2;
};

