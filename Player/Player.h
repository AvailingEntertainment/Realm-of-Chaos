/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Logan
 *
 * Created on February 29, 2016, 1:56 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

int inventory[] =
{
  0,0,0,0,0,0,0,0,0,0,0,0,0,0 // 14 items in the backpack  
};

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
private:

};

#endif /* PLAYER_H */

