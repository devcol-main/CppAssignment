
#include "11_Magician.h"


void Magician::attack(Monster* monster)
{
	//cout << "Magician Attack \n";
	
	int damage = (power - monster->getDefence());	
	
	if (damage < 1) damage = 1;
	
	cout << "[Mage] Fires fireball! -> " << damage << " damage to " << monster->getMonsterName() <<"!\n";
	
	monster->setDamageAttackedFromPlayer(damage);

}

void Magician::printSelectedClass()
{
	cout << "Magician Selected \n";
}



