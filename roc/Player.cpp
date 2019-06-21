#include "Player.h"

Player::Player()
{
	
}

int Player::playerCoord(int xy)
{
	if (xy == 1)
		return playerY;
	else if (xy == 2)
		return playerX;
}