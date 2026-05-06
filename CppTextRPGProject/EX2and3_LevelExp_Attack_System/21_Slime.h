#pragma once
#include "20_Monster.h"

class Slime : public Monster
{
    
private:
    void initializing();
 
public:

    /*
    Slime(string name, int hp, int power, int defence
        ,int dropItemPrice, string dropItemName) 
    : Monster(name, hp, power, defence, dropItemPrice, dropItemName)
    {
        initializing();
    }
    */
    Slime() 
    {
        initializing();       
    }
    
    //
    //void attack(Player* player) override;
    //void getDamagedFromPlayer(int damage) override;
    
   
    
    /*
    *  Monster(string name, 
        int hp, int power, int defence, 
        int dropItemPrice, string dropItemName) 
    : name(name), hp(hp), power(power), defence(defence), dropItemPrice(dropItemPrice), dropItemName(dropItemName) {}
    
     */
};

 
