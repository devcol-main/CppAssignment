
#include "11_Thief.h"


void Thief::attack(Monster* monster)
{
	//cout << "Thief Attack \n";
	
	int attackCount = 5; // should be in header
	
	int damage = (power - monster->getDefence()) / 5;
	if (damage < 1) damage = 1;
	
	for (int i=0; i < attackCount ; i++)
	{
		cout << "[Rogue] Stabs dagger! -> " << damage << " damage to " << monster->getMonsterName() <<"!\n";
		monster->setDamageAttackedFromPlayer(damage);
	}
	
	//monster->setDamageAttackedFromPlayer(damage)
}

void Thief::printSelectedClass()
{
	cout << "Thief Selected \n";
}



