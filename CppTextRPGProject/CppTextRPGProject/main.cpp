// CppTextRPGProject.cpp : Start Date: 4/28/2026


#include <iostream>

//
using namespace std;


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

void endingCredit();

//
enum STATS { STATS_HP, STATS_MP, STATS_Attack, STATS_Defense };

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
	printGameTitle();
	heroName = enterName();	
	enterStats(stat);


	printStatus(heroName, stat);
	//
	
	//
	printStatManageMenu();

	// choice
	
	upgradeStatMenu(heroName, stat, HealthPotion, ManaPotion, isGameStart, HealthPotionIncreaseAmount,
	                ManaPotionIncreaseAmount);
	//
	
	
	//Player player(heroName, stat[STATS_HP], stat[STATS_MP], stat[STATS_Attack], stat[STATS_Defense]);
		


	//
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



void jobSelection()
{
	cout << "< Job Selection >\n";
	
	cout << ", choose your job!\n";
	cout << "1. Warrior   2. Mage   3. Rogue   4. Archer\n";
	cout << "Choose: "; //cin >> ; 
	cout << "------------------------------------\n";

	cout << "------------------------------------\n";
/*

< Job Selection >
John, choose your job!
1. Warrior   2. Mage   3. Rogue   4. Archer
Choose: 2
* You became a Mage! (MP +30)
* Fires a fireball!
------------------------------------
Name: John | Job: Mage | Lv.1
HP: 80 | MP: 90 | Attack: 40 | Defense: 25
------------------------------------

*/
}


//
void endingCredit()
{

	cout << "\n\n\n\n";
	cout << "Created by in9 | Date: 2026/05/ " << endl;
}
