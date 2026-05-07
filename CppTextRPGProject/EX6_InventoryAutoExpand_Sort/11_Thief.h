#pragma once
#include "10_Player.h"

class Thief : public Player
{
public:
    Thief(string name, JOB job, int hp,int mp, int power, int defence) 
    : Player(name,job,hp,mp,power,defence){}

    void attack(Monster* monster) override;
    void printSelectedClass() override;
    
    //
    //void printPlayerStatus();
    

};
