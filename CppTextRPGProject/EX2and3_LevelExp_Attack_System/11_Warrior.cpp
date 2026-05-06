
#include "11_Warrior.h"


void Warrior::attack(Monster* monster)
{
	//cout << "Warrior Attack \n";
	int damage = (power - monster->getDefence());	
	if (damage < 1) damage = 1;
	cout << "[Warrior] Swings sword! -> " << damage << " damage to " << monster->getMonsterName() <<"!\n";
	
	monster->setDamageAttackedFromPlayer(damage);
}

void Warrior::printSelectedClass()
{
	cout << "Warrior Selected \n";
}



