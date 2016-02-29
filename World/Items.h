/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Items.h
 * Author: Logan
 *
 * Created on February 29, 2016, 1:59 PM
 */

#ifndef ITEMS_H
#define ITEMS_H

char *item_name[] =
{
  ""  
};

int item_stats[][] =
{
    /*
     * TYPE     - 0
     * QUAL     - 1
     * MIN DMG  - 2
     * MAX DMG  - 3
     * ATK PWR  - 4
     * SPL PWR  - 5
     * AC       - 6 
     * STR      - 7
     * STA      - 8
     * AGI      - 9
     * INT      - 10
     * SPI      - 11
     * HP       - 12
     * MP       - 13
     * CRT      - 14
     * HIT      - 15
     * DDG      - 16
     * PRY      - 17
     * BLK      - 18
     * BV       - 19
     */
    {}  
};

class Items {
public:
    Items();
    Items(const Items& orig);
    virtual ~Items();
private:

};

#endif /* ITEMS_H */

