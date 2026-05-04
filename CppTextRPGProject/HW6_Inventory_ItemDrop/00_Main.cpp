// CppTextRPGProject.cpp
// Start Date: 4/28/2026


#include <iostream>

//
//#include "10_Player.h"

#include "11_Warrior.h"
#include "11_Magician.h"
#include "11_Thief.h"
#include "11_Archer.h"

//
//#include "20_Monster.h"
#include "21_Slime.h"

#include <vector>
//
using namespace std;

enum STATS { STATS_HP, STATS_MP, STATS_Attack, STATS_Defense };

struct Item
{
	string itemName;
	int itemPrice;
	void PrintInfo() const
	{
		cout << itemName << " (" << itemPrice << "G)\n";
	}
};

//
void printGameTitle();
string enterName();
void enterStats(int stat[4]);

void printStatus(string name, int stat[]);
void printStatManageMenu();
void printStatChoices();

void upgradeStatMenu(string heroName, 
	int stat[4], int HealthPotion, int ManaPotion, bool isGameStart, 
	int HealthPotionIncreaseAmount, int ManaPotionIncreaseAmount);


int printJobChoice(string heroName);
int jobSelect(string heroName);

void createPlayerWithJob(string heroName, int stat[4], Player*& player, int selectedJobNum);
void startBattleWithMonster(Player* player, Slime monster, vector<Item> inventory);

void endingCredit();

// ===============================================

int main()
{
	
	//
	string heroName;
	const int SIZE = 4; int stat[SIZE] = { 0 }; //HP, MP, Attack, Defense;

	int HealthPotion = 5, ManaPotion = 5;
	bool isGameStart = false;
	
	// custom
	int HealthPotionIncreaseAmount = 20, ManaPotionIncreaseAmount = 20;
	//
	Player* player = nullptr;
	
	
	
	//	
	int currentMaxInventroySize = 10;
	vector<Item> inventory; 
	
	//
	Item item;
	item.itemName = "Slime Jelly";
	item.itemPrice = 30;
	
	
	//inventory.insert(inventory.begin(), item);
	inventory.push_back(item);	
	
	//cout << "in size : " << inventory.size() <<endl;	
	//cout << "in " << inventory[0].itemName << " " <<inventory[0].itemPrice << endl;
	
	//
	printGameTitle();
	heroName = enterName();	
	enterStats(stat);


	printStatus(heroName, stat);	
	
	printStatManageMenu();

	
	upgradeStatMenu(heroName, stat, HealthPotion, ManaPotion, isGameStart, HealthPotionIncreaseAmount,
	                ManaPotionIncreaseAmount);
	
	int selectedJobNum = jobSelect(heroName);
	
	createPlayerWithJob(heroName, stat, player, selectedJobNum);
	
	// Main Menu
	
	
	// menu selection.
	while (true)
	{
		int selectedMenuNum = 0;
		cout << "\n=== Main Menu ===\n";
		cout << "1. Enter Dungeon\n";
		cout << "2. Check Inventory\n";
		cout << "0. Quit\n";
		
		cout << "\nChoose: "; cin >> selectedMenuNum;
		
		if (1 == selectedMenuNum)
		{
			cout << "Enter Dungeon\n";
			break;
		}		
		else if (2 == selectedMenuNum)
		{
			int num = 1;	
			cout << "[ Inventory (" <<inventory.size() << "/" << currentMaxInventroySize << ") ]\n";				
				
			for (auto items : inventory)
			{
				cout<< num << ". " << items.itemName << " (" << items.itemPrice << "G)\n";
				++num;
			}
			/*
			 for (int i = 0; i < inventory.size(); ++i)
			{
				inventory[i].PrintInfo();
			}
			*/
		}		
		else if (0 == selectedMenuNum)
		{
			cout << "Quit\n";
			return 0;
		}
		else
		{
			cout << "!!!!! Wrong Choice !!!!!\n";
			cout << "Press 1 or 2 or 0\n";
			cout << "\n";
		}
		
	}
	
	
	
	
	// Start Balltle
	player->attack();
	
	cout << "------------------------------------\n";
	player->printPlayerStatus();
	cout << "------------------------------------\n";
	
	
	// Enter battle loop	
	Slime monster;	
	startBattleWithMonster(player, monster, inventory);
	
	//
	delete player;
	endingCredit();
}

// ====== func

void printGameTitle()
{

	cout << "===========================================\n";
	cout << "   [Dungeon Escape Text RPG]\n";
	cout << "===========================================\n";

}

string enterName()
{
	string heroName;

	cout << "Enter your hero's name: "; cin >> heroName; // I puted in same line just to see easily
	cout << "\n";

	return heroName;
}


void enterStats(int stat[4])
{
	while (true)
	{
		cout << "Enter HP and MP: "; cin >> stat[STATS_HP] >> stat[STATS_MP]; // To stay in same line, user has to press space after hp

		// HP와 MP가 모두 50보다 클 때만 break로 입력 루프 탈출하기
		if (stat[STATS_HP] > 50 && stat[STATS_MP] > 50)
		{
			break;

		}
		else
		{
			cout << "HP or MP is too low.Try again\n";
		}

	}

	while (true)
	{
		cout << "Enter Attack and Defense: "; cin >> stat[STATS_Attack] >> stat[STATS_Defense]; // In order to stay in same line, user has to press space after hp

		// Attack, Defense가 모두 50보다 클 때만 break로 입력 루프 탈출하기
		if (stat[STATS_Attack] > 50 && stat[STATS_Defense] > 50)
		{
			break;
		}
		else
		{
			cout << "Attack or Defense is too low. Try again.\n";

		}

	}

	cout << "\n";
}

void printStatus(string name, int stat[])
{
	cout << "====================================\n";
	cout << "  ";cout << name << "s Stats\n";
	cout << "====================================\n";
	cout << "HP: " << stat[STATS_HP];  cout << "    "; cout << "MP: " << stat[STATS_MP]; cout << "\n";
	cout << "Attack: " << stat[STATS_Attack];  cout << "    "; cout << "Defense: " << stat[STATS_Defense]; cout << "\n";
	cout << "====================================\n";
}

void printStatManageMenu()
{

	cout << "\n\n";
	cout << "* You received 5 HP Potions and 5 MP Potions.\n";
	printStatChoices();


}

void printStatChoices()
{
	cout << "====================================\n";
	cout << "< Character Upgrade >\n";
	cout << "1. HP UP    2. MP UP    3. Attack x2\n";
	cout << "4. Defense x2  5. Show Stats  0. Start Game\n";
	cout << "====================================\n";
}


void upgradeStatMenu(string heroName, 
	int stat[4], int HealthPotion, int ManaPotion, bool isGameStart, 
	int HealthPotionIncreaseAmount, int ManaPotionIncreaseAmount)
{
	while (!isGameStart)
	{
		int choice = 0;
		enum ChoiceSelect {
			ChoiceSelect_HPUP = 1, ChoiceSelect_MPUP = 2,
			ChoiceSelect_AttackDouble = 3, ChoiceSelect_DefenseDouble = 4,
			ChoiceSelect_ShowStats = 5, ChoiceSelect_StartGame = 0
		};

		cout << "Choose: "; cin >> choice;

		switch (choice)
		{
		case ChoiceSelect_HPUP:
			{
				if (HealthPotion > 0)
				{
					--HealthPotion;

					cout << "* HP increased by " << HealthPotionIncreaseAmount << ". (HP Potion used : " << HealthPotion << " left)\n";
					stat[STATS_HP] += HealthPotionIncreaseAmount;

				}
				else
				{
					cout << "Not Enough Health Potion\n";
				}


			}
			break;

		case ChoiceSelect_MPUP:
			{
				if (ManaPotion > 0)
				{
					--ManaPotion;

					cout << "* MP increased by " << ManaPotionIncreaseAmount << ". (MP Potion used : " << ManaPotion << " left)\n";
					stat[STATS_MP] += ManaPotionIncreaseAmount;

				}
				else
				{
					cout << "Not Enough Mana Potion\n";
				}


			}
			break;

		case ChoiceSelect_AttackDouble:
			{
				stat[STATS_Attack] *= 2;

				cout << "Attack Stat Doubled! New Attack Stat: " << stat[STATS_Attack] << endl;

			}
			break;

		case ChoiceSelect_DefenseDouble:
			{
				stat[STATS_Defense] *= 2;

				cout << "Defense Stat Doubled! New Defense Stat: " << stat[STATS_Defense] << endl;

			}
			break;

		case ChoiceSelect_ShowStats:
			{

				cout << "Display current stats\n";
				printStatus(heroName, stat);

			}
			break;


		case ChoiceSelect_StartGame:
			{
				cout << "Game Start!\n";
				isGameStart = true;

			}
			break;



		default:
			{
				cout << "!!!!! Wrong Choice !!!!!\n";
				cout << "Press from 0 ~ 5\n";
				cout << "\n";
				printStatChoices();
			}
			break;
		}
	}
}


int printJobChoice(string heroName)
{
	int selectedJobNum = 0;
	
	cout << "\n< Job Selection >\n";	
	cout << heroName; cout << ", choose your job!\n";
	cout << "1. Warrior   2. Magician   3. Thief   4. Archer\n";
	// from player enum JOB { JOB_Warrior = 0, JOB_Magician, JOB_Thief, JOB_Archer };
	
	cout << "Choose: "; cin >> selectedJobNum;
	// to match with enum index 0~3
	return (--selectedJobNum);
}

int jobSelect(string heroName)
{
	int selectedJobNum = printJobChoice(heroName);	
	
	
	while (true)
	{
		if (selectedJobNum < 0 || selectedJobNum > 3)
		{
			cout << "\n!!!!! Wrong Choice !!!!!\n";
			cout << "Press from 1 ~ 4\n";
			cout << "\n";
			
			// from player enum JOB { JOB_Warrior = 0, JOB_Magician, JOB_Thief, JOB_Archer };	
			selectedJobNum = printJobChoice(heroName);	
		}
		else
		{
			break;
		}		
	}	
	
	return selectedJobNum;	
	
}


void createPlayerWithJob(string heroName, int stat[4], Player*& player, int selectedJobNum)
{
	switch (selectedJobNum)
	{
	case JOB_Warrior:
		{
			cout << "You became a Warrior! (Defense +30)\n";
			stat[STATS_Defense] += 30;
				
			player = new Warrior(heroName, JOB_Warrior,
								 stat[STATS_HP], stat[STATS_MP],stat[STATS_Attack] , stat[STATS_Defense]);
		}
		break;
		
	case JOB_Magician:
		{
			cout << "You became a Mage! (MP +30)\n";	
			stat[STATS_MP] += 30;
				
			player = new Magician(heroName, JOB_Magician,
								  stat[STATS_HP], stat[STATS_MP],stat[STATS_Attack] , stat[STATS_Defense]);			
				
		}
		break;
		
	case JOB_Thief:
		{
			cout << "You became a Thief! (HP +30)\n";
			stat[STATS_HP] += 30;
				
			player = new Thief(heroName, JOB_Thief,
							   stat[STATS_HP], stat[STATS_MP],stat[STATS_Attack] , stat[STATS_Defense]);
		}
		break;
		
	case JOB_Archer:
		{
			cout << "You became a Archer! (Power +30)\n";
			stat[STATS_Attack] += 30;
				
			player = new Archer(heroName, JOB_Archer,
								stat[STATS_HP], stat[STATS_MP],stat[STATS_Attack] , stat[STATS_Defense]);
		}
		break;		
	}
}

void startBattleWithMonster(Player* player, Slime monster, vector<Item> inventory)
{
	cout << "\n";
	cout<< "[ Battle Start! ] " << player->getPlayerName() 
		<< "(" << player->getPlayerJobname() << ")" 
		<< " vs " << monster.getMonsterName() << "\n\n";  
	
	while (player->getPlayerHP() > 0 && monster.getHP() > 0)
	{
		
		// Player Turn
		cout << "--- Player Turn ---\n";	
		//
		player->attack(); // plain text
	
		//	
	
		if (monster.setDamageAttackedFromPlayer(player->getPlayerPower()))
		{
			// true monster dead
			// battle end
			cout << "\nVictory!\n";
			cout << "-> Got: " << monster.getDropItemName() << "!\n";
			inventory.push_back(Item{ monster.getDropItemName(), monster.getDropItemPrice() });
			cout << "-> Saved to inventory.\n";
		
		}
		else
		{
			// false monster is not dead
			// monster attack
			cout << "\n--- Monster Turn ---\n";
			monster.attack(player);
			
			if (player->getPlayerHP() <= 0)
			{
				cout<< "\nPlayer DEAD\n" << "\nGAME OVER\n";
			}
			
		
		}
	}
}


//
void endingCredit()
{

	cout << "\n\n";
	cout << "Created by in9 | Date: 2026/05/ " << endl;
}
