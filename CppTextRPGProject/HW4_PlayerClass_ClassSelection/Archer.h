#pragma once
#include "Player.h"

class Archer  : public Player
{
public:
    Archer(string name, JOB job, int hp,int mp, int power, int defence) 
    : Player(name,job,hp,mp,power,defence){}

    void attack() override;
    void printSelectedClass() override;
    
    //
    //void printPlayerStatus();
    

};
