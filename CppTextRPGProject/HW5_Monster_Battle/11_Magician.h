#pragma once
#include "10_Player.h"

class Magician : public Player
{
public:
    Magician(string name, JOB job, int hp,int mp, int power, int defence) 
    : Player(name,job,hp,mp,power,defence){}

    void attack() override;
    void printSelectedClass() override;
    
    //
    //void printPlayerStatus();
    

};
