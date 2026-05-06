// CppTextRPGProject.cpp
// Start Date: 4/28/2026


#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <string>


//
//#include "10_Player.h"

#include "11_Warrior.h"
#include "11_Magician.h"
#include "11_Thief.h"
#include "11_Archer.h"

//
//#include "20_Monster.h"
#include "21_Slime.h"
#include "22_Goblin.h"


//
using namespace std;

enum STATS { STATS_HP, STATS_MP, STATS_Attack, STATS_Defense };

struct ItemInfo
{
	string itemName;
	int itemPrice;
	void PrintInfo() const
	{
		cout << itemName << " (" << itemPrice << "G)\n";
	}
};

struct PotionRecipe
{
	string potionName;
	string ingredientName1;
	string ingredientName2;
	map<string, int> ingredientMap;   
    
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

//

void generateRandomMonster(Monster& monster);
void startBattleWithMonster(Player* player, Monster monster, vector<ItemInfo>& inventory);

// potion shop
void showAllRecipes(vector<PotionRecipe> allPotionInfo);
bool searchByName(vector<PotionRecipe> allPotionInfo, string potionName);
bool searchByIngredient(vector<PotionRecipe> allPotionInfo,string ingredientName);
void displayPotionShopMenu(vector<PotionRecipe> allPotionInfo); // 추후 여기서 제작한거 저장 하려면 &레퍼런스나 *포인터로 변경하자


// ===== Extras =====
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

//
void endingCredit();

// ===============================================


int main()
{
	// ===============================================
	// === Potion shop ===
	string const HPPOTION = "HPPotion";
	string const STAMINA_POTION = "StaminaPotion";
    
	string const HERB = "Herb";
	string const CLEAR_WATER = "Clear Water";
	string const BERRY = "Berry";
    
	//
	vector<PotionRecipe> allPotionInfo;  
    
	//
	PotionRecipe hpPotionRecipe;
    
	hpPotionRecipe.potionName = HPPOTION;
    
	hpPotionRecipe.ingredientName1 = HERB;
	hpPotionRecipe.ingredientMap[HERB] = 1;
    
	hpPotionRecipe.ingredientName2 = CLEAR_WATER;
	hpPotionRecipe.ingredientMap[CLEAR_WATER] = 1;
    
	//
	PotionRecipe staminaPotionRecipe;
	staminaPotionRecipe.potionName = STAMINA_POTION;
	staminaPotionRecipe.ingredientName1 = HERB;
	staminaPotionRecipe.ingredientMap[HERB] = 1;
	staminaPotionRecipe.ingredientName2 = BERRY;
	staminaPotionRecipe.ingredientMap[BERRY] = 1;   
    
	//
	allPotionInfo.push_back(hpPotionRecipe);
	allPotionInfo.push_back(staminaPotionRecipe);
	
	// =================================================
	string heroName;
	const int SIZE = 4; int stat[SIZE] = { 0 }; //HP, MP, Attack, Defense;

	//int HPPotion = 5, MPPotion = 5;
	int HPPotion = 0, MPPotion = 0;
	
	setPotion(5,  &HPPotion, &MPPotion);
	
	bool isGameStart = false;
	
	// custom
	int HealthPotionIncreaseAmount = 20, ManaPotionIncreaseAmount = 20;
	
	//
	Monster monster = Monster();
	
	
	//
	Player* player = nullptr;
	
	//
	
	
	
	//	
	int currentMaxInventroySize = 10;
	vector<ItemInfo> inventory; 
	
	//
	ItemInfo item;
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

	
	upgradeStatMenu(heroName, stat, HPPotion, MPPotion, isGameStart, HealthPotionIncreaseAmount,
	                ManaPotionIncreaseAmount);
	
	int selectedJobNum = jobSelect(heroName);
	
	createPlayerWithJob(heroName, stat, player, selectedJobNum);
	
	// Main Menu
	while (true)
	{
		// Menu selection.
		while (true)
		{
			int selectedMenuNum = 0;
			cout << "\n=== Main Menu ===\n";
			cout << "1. Enter Dungeon\n";
			cout << "2. Check Inventory\n";
			cout << "3. Potion Shop\n";
			cout << "0. Quit\n";
		
			cout << "\nChoose: "; cin >> selectedMenuNum;
		
			if (1 == selectedMenuNum)
			{
				cout << "Enter Dungeon\n";
				break;
			}
			
			if (2 == selectedMenuNum)
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
			
			else if (3 == selectedMenuNum)
			{
				displayPotionShopMenu(allPotionInfo);
			}
			
			else if (0 == selectedMenuNum)
			{
				cout << "Quit\n";
				
				delete player;
				endingCredit();
				
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
		//player->attack(); // TODO: TO Be Delete
	
		cout << "------------------------------------\n";
		player->printStatus();
		cout << "------------------------------------\n";
	
		
		generateRandomMonster(monster);
		startBattleWithMonster(player, monster, inventory);
	
		//
		
	
	}
	
	
	
	
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
		cout << "Enter Attack and Defense: "; cin >> stat[STATS_Attack] >> stat[STATS_Defense]; // To stay in same line, user has to press space after hp

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



void generateRandomMonster(Monster& monster)
{

	// 1. Obtain a random number from hardware to seed the generator
	random_device rd;     
	// 2. Initialize the Mersenne Twister engine with the seed
	mt19937 gen(rd()); 
	// 3. Define the range [1, 2] (inclusive)
	uniform_int_distribution<> dist(1, 2);

	// 4. Generate the number
	int random_num = dist(gen);	
	//cout << "Random Number: " << random_num << endl;
	// select monster
		
	//Monster monster = Monster(); // TODO: TO Be Delete
	
	if (random_num == 1)
	{		
		monster = Slime();
	}
	else if (random_num == 2)
	{
		monster = Goblin();
	}
}

void startBattleWithMonster(Player* player, Monster monster, vector<ItemInfo>& inventory)
{
	cout << "\n";
	cout<< "[ Battle Start! ] " << player->getName() 
		<< "(" << player->getJobname() << ")" 
		<< " vs " << monster.getMonsterName() << "\n\n";  
	
	while (player->getHP() > 0 && monster.getHP() > 0)
	{
		
		// Player Turn
		cout << "--- Player Turn ---\n";	
		//
		
		player->attack(&monster);	
		
		if (monster.getIsDead())
		{
			// true monster dead
			// battle end
			cout << "\nVictory!\n";
			cout << "-> Got: " << monster.getDropItemName() << "!\n";
			inventory.push_back(ItemInfo{ monster.getDropItemName(), monster.getDropItemPrice() });
			cout << "-> Saved to inventory.\n";
			
			//		
			player->setExp(monster.getExpReward()); // returns bool (true if lvl up)
	
		
		}
		else
		{
			// false monster is not dead
			// monster attack
			cout << "\n--- Monster Turn ---\n";
			monster.attack(player);
			
			if (player->getHP() <= 0)
			{
				cout<< "\nPlayer DEAD\n" << "\nGAME OVER\n";
			}			
		
		}	
	
	}
}


//
void showAllRecipes(vector<PotionRecipe> allPotionInfo)
{
	for (int i = 0; i < allPotionInfo.size(); i++)
	{        
		//cout << i <<". " 
		cout << "-> " << allPotionInfo[i].potionName 
		<< " (" << allPotionInfo[i].ingredientName1 << " x"<< allPotionInfo[i].ingredientMap[allPotionInfo[i].ingredientName1]
		<< ", " << allPotionInfo[i].ingredientName2 << " x"<< allPotionInfo[i].ingredientMap[allPotionInfo[i].ingredientName2] << ")\n";
		
	}
	cout << endl;   
    
}

bool searchByName(vector<PotionRecipe> allPotionInfo, string potionName)
{
	for (auto p : allPotionInfo)
	{
		if (p.potionName == potionName)
		{
			cout << "-> " << p.potionName 
			<< " (" << p.ingredientName1 << " x" << p.ingredientMap[p.ingredientName1] 
			<< ", " << p.ingredientName2 << " x" << p.ingredientMap[p.ingredientName2] << ")\n";
            
			return true;           
		} 
	}  

    
	cout << "No such potion\n";
	cout << "All potion names: ";
	for (auto p : allPotionInfo)
	{
		cout << p.potionName << "   ";
	}   
    
	cout << endl;
    
	return false;
}

bool searchByIngredient(vector<PotionRecipe> allPotionInfo,string ingredientName)
{
    
	int numFound = 0;
    
	for (auto p : allPotionInfo)
	{
		if (p.ingredientMap.find(ingredientName) != p.ingredientMap.end())
		{
			cout << "-> " << p.potionName 
			<< " (" << p.ingredientName1 << " x" << p.ingredientMap[p.ingredientName1] 
			<< ", " << p.ingredientName2 << " x" << p.ingredientMap[p.ingredientName2] << ")\n";
            
			++numFound;
		}        
	}
    
	cout << "Found " << numFound << "\n";
    
	if (0 == numFound)
	{
		cout << "No such ingredient\n";
		return false;   
	} 

    
	return true;    
}


void displayPotionShopMenu(vector<PotionRecipe> allPotionInfo)
{
	while (true)
	{
		//
		cout << "\n=== Potion Shop ===\n";
		cout << "1. Show all recipes\n";
		cout << "2. Search by potion name\n";
		cout << "3. Search by ingredient\n";
		cout << "0. Go back\n";
        
		//
		int potionShopChoice = 0;
		cout << "\nChoose: "; cin >> potionShopChoice;
        
        
		//
		if (0 == potionShopChoice)
		{
			cout << "0. Go back\n";
			break;
		}
		else if (1 == potionShopChoice)
		{
			//cout << "1. Show all recipes\n";
			showAllRecipes(allPotionInfo);
		}
		else if (2 == potionShopChoice)
		{
			string tempName;
			cout << "Search potion name: "; cin >> tempName;
            
			searchByName(allPotionInfo,tempName);
            
		}
		else if (3 == potionShopChoice)
		{
			string tempName;
			cout << "Search ingredient: ";

			cin.ignore(); // 버퍼 비우기 (필수) // getline 전에 내가 cin 썻으니 써야한다.

			getline(cin, tempName); // inorder to include space need to use getline (#include <string>)             
            
			searchByIngredient(allPotionInfo ,tempName);
            
            
		}
		else
		{
			cout << "!!Wrong choice\n";
		}
	}
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count; 
	*p_MPPotion = count;
}

//
void endingCredit()
{

	cout << "\n\n";
	cout << "Created by in9 | Date: 2026/05/ " << endl;
}
