#include "20_Monster.h"

void Monster::attack(Player* player)
{
    cout << name <<" Attack\n";
    
    player->setDamageAttackedFromMonster(power);
    //(void)player;
}

string Monster::getMonsterName() {return  name;}
string Monster::getDropItemName(){ return dropItemName;}

int Monster::getHP() { return hp; }
int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }
int Monster::getDropItemPrice() { return dropItemPrice; }


//
bool Monster::setDamageAttackedFromPlayer(int damage)
{
    bool isDead = false;
   
    int fixedDamage = 1;
    int originHP = hp;    
    int calIncompingDamage = 0;
    
    cout << damage << " damage to " << name << "!";
    
    calIncompingDamage = defence - damage;   
    
    // just to show it txt...
    calIncompingDamage *= -1;
    
    
    if (calIncompingDamage > 0)
    {
        hp -= calIncompingDamage;
    }
    else
    {
        calIncompingDamage = fixedDamage;
        hp -= calIncompingDamage;
    }
    cout << " | Actual Damage: " << calIncompingDamage << " (defense - damage)\n";
    
    cout << name << " HP: " << originHP << " -> " << hp;
    
    string status = "";
    
    if (hp <= 0)
    {
        status = "Dead";    
        isDead = true;
    }
    else
    {
        status = "Alive";
        isDead = false;       
    }
    
    cout << " (" << status << ")\n";
    
    return isDead;
    
}
