
#include "10_Player.h"

//

void Player::printPlayerStatus()
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
    
    cout << "Exp: " << exp << " / " << maxExp << endl;   
}

// getter

string Player::getPlayerName()
{
    return name;
}

string Player::getPlayerJobname()
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

int Player::getPlayerLevel() {return level; }

int Player::getPlayerHP() {return hp; }
int Player::getPlayerMP() {return mp; }


int Player::getPlayerPower() {return power; }
int Player::getPlayerDefense() {return defence; }

int Player::getPlayerExp() {return exp; }
int Player::getPlayerMaxExp() {return maxExp; }

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

bool Player::setPlayerExp(int exp)
{
    this->exp += exp;
    if (this->exp >= maxExp)
    {
        //this->exp -= maxExp;
        this->exp = 0;
        levelUp();
        
        return true;
    }
    
    cout << "-> +" << exp << " EXP! (EXP: " << this->exp << "/" << maxExp << ")\n";
    
    return false;
}

void Player::levelUp()
{
    cout << "\n... Level up condition met\n";
    cout << "  -> Level Up! " << "Lv." << level << " -> ";
    
    level++;    
    cout << "Lv." << level << endl;
    
    // TODO: Should be in variable... but let it be for now. 
    hp += 10;
    mp += 5;
    power += 5;
    defence += 5;    
    maxExp += maxExpIncreaseAmount;
    
    cout << "  -> HP +10, MP +5, Attack +5\n";
    
}




