
#include "Player.h"

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
}
