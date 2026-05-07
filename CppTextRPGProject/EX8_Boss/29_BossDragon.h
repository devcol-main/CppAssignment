#pragma once
#include "20_Monster.h"

class BossDragon : public Monster
{
    
private:
    void initializing();
 
public:    
    BossDragon() 
    {
        initializing();       
    }   

};

 
