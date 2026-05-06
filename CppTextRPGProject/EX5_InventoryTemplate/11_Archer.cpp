
#include "11_Archer.h"


void Archer::attack(Monster* monster)
{
	
	int attackCount = 3; // should be in header
	
	int damage = (power - monster->getDefence()) / 3;
	
	if (damage < 1) damage = 1;
	
	for (int i=0; i < attackCount ; i++)
	{
		cout << "[Archer] Shoots arrow! -> " << damage << " damage to " << monster->getMonsterName() <<"!\n";	
		
		monster->setDamageAttackedFromPlayer(damage);
	}
	
	
}

void Archer::printSelectedClass()
{
	cout << "Archer  Selected \n";
}



