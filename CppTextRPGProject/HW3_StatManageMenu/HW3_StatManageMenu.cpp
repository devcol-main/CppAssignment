// CppTextRPGProject.cpp : Start Date: 4/28/2026


#include <iostream>
using namespace std;


//
void printStatus(string name, int stat[]);
void PrintStatManamgeMenu();
void PrintStatChoices();

//
enum STATS { STATS_HP, STATS_MP, STATS_Attack, STATS_Defense };

int main()
{
	cout << "HW3_StatManageMenu" << endl;

	//
	string heroName;
	const int SIZE = 4; int stat[SIZE] = { 0 }; //HP, MP, Attack, Defense;

	int HealthPotion = 5, ManaPotion = 5;
	bool isGameStart = false;

	// custom
	int HealthPotionIncreaseAmount = 20, ManaPotionIncreaseAmount = 20;

	cout << "===========================================" << endl;
	cout << "   [Dungeon Escape Text RPG]" << endl;
	cout << "===========================================" << endl;

	cout << "Enter your hero's name: "; cin >> heroName; // I puted in same line just to see easily
	cout << "\n";

	//
	while (true)
	{
		cout << "Enter HP and MP: "; cin >> stat[STATS_HP] >> stat[STATS_MP]; // In order to stay in same line, user has to press space after hp

		// HP와 MP가 모두 50보다 클 때만 break로 입력 루프 탈출하기
		if (stat[STATS_HP] > 50 && stat[STATS_MP] > 50)
		{
			break;

		}
		else
		{
			cout << "HP or MP is too low.Try again" << endl;
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
			cout << "Attack or Defense is too low. Try again." << endl;

		}

	}

	cout << "\n";


	printStatus(heroName, stat);
	//


	//
	PrintStatManamgeMenu();

	// choice
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

				cout << "* HP increased by " << HealthPotionIncreaseAmount << ". (HP Potion used : " << HealthPotion << " left)" << endl;
				stat[STATS_HP] += HealthPotionIncreaseAmount;
				
			}
			else
			{
				cout << "Not Enough Health Potion" << endl;
			}
			

		}
		break;

		case ChoiceSelect_MPUP:
		{
			if (ManaPotion > 0)
			{
				--ManaPotion;

				cout << "* MP increased by " << ManaPotionIncreaseAmount << ". (MP Potion used : " << ManaPotion << " left)" << endl;
				stat[STATS_MP] += ManaPotionIncreaseAmount;
				
			}
			else
			{
				cout << "Not Enough Mana Potion" << endl;
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

			cout << "Display current stats" << endl;
			printStatus(heroName, stat);

		}
		break;


		case ChoiceSelect_StartGame:
		{
			cout << "Game Start!" << endl;
			isGameStart = true;
			
		}
		break;



		default:
		{
			cout << "!!!!! Wrong Choice !!!!!" << endl;
			cout << "Press from 0 ~ 5" << endl;
			cout << "\n";
			PrintStatChoices();
		}
			break;
		}
	}

}

void printStatus(string name, int stat[])
{
	cout << "====================================" << endl;
	cout << "  ";cout << name << "s Stats" << endl;
	cout << "====================================" << endl;
	cout << "HP: " << stat[STATS_HP];  cout << "    "; cout << "MP: " << stat[STATS_MP]; cout << "\n";
	cout << "Attack: " << stat[STATS_Attack];  cout << "    "; cout << "Defense: " << stat[STATS_Defense]; cout << "\n";
	cout << "====================================" << endl;
}

void PrintStatManamgeMenu()
{

	cout << "\n" << endl;
	cout << "* You received 5 HP Potions and 5 MP Potions." << endl;
	PrintStatChoices();


}

void PrintStatChoices()
{
	cout << "====================================" << endl;
	cout << "< Character Upgrade >" << endl;
	cout << "1. HP UP    2. MP UP    3. Attack x2" << endl;
	cout << "4. Defense x2  5. Show Stats  0. Start Game" << endl;
	cout << "====================================" << endl;
}

