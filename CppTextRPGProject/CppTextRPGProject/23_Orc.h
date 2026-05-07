#pragma once
#include "20_Monster.h"

class Orc : public Monster
{
    
private:
    void initializing();
 
public:    
    Orc() 
    {
        initializing();       
    }   

};

 
