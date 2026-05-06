
#include "10_Player.h"

//

void Player::printStatus()
{
    //cout << "1. Warrior   2. Magician   3. Thief   4. Archer\n";
    string jobName = "";
    switch (job)
    {
        case JOB_Warrior: jobName = "Warrior"; break;
        case JOB_Magician: jobName = "Magician"; break;
        case JOB_Thief: jobName = "Thief"; break;
        case JOB_Archer: jobName = "Archer"; break;
    }
    
    cout << "Name: " << name << " | Job: " << jobName << " | Lv." << level << endl;

    cout <<  "HP: " << hp << " | MP: " << mp << " | Attack: " << power << " | Defense: " << defence << endl;
}

// getter

string Player::getName()
{
    return name;
}

string Player::getJobname()
{
    string jobName = "";
    
    switch (job)
    {
    case JOB_Warrior: jobName = "Warrior"; break;
    case JOB_Magician: jobName = "Magician"; break;
    case JOB_Thief: jobName = "Thief"; break;
    case JOB_Archer: jobName = "Archer"; break;
    }
    
    return  jobName;
}

int Player::getLevel() {return level; }

int Player::getHP() {return hp; }
int Player::getMP() {return mp; }


int Player::getPower() {return power; }
int Player::getDefense() {return defence; }

// ====== Setter

bool Player::setDamageAttackedFromMonster(int damage)
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

