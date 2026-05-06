#include "21_Slime.h"

#include "90_GlobalVariable.h"


void Slime::initializing()
{
    name = "Slime";
    hp = 30;
    power = 20;
    defence = 10;
    dropItemName = SLIME_JELLY; // "Slime Jelly";
    dropItemPrice = 30;
    
    //Slime slime("Slime", 10, 5, 2, 10, "Slime Jelly");
}

/*void Slime::attack(Player* player)
{
    cout << name << " Attacked Player\n";
}*/

/*
void Slime::setDamageAttackedFromPlayer(int damage)
{
    
}
*/
