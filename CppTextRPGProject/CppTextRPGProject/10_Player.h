#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "20_Monster.h"
using namespace std;


enum JOB { JOB_Warrior = 0, JOB_Magician, JOB_Thief, JOB_Archer };	

class Player
{

protected:
	// variables
	string name;
	JOB job;
	int level, hp, mp, power, defence;
	int exp = 0;
	int maxExp = 100;
	const int maxExpIncreaseAmount = 10;
	

public:
	
	Player(string name, JOB job, int hp, int mp, int power, int defense) :
	name(name), job(job), hp(hp), mp(mp), power(power), defence(defense)
	{
		level = 1;
	}

	// pure virtual func	
	virtual void attack(Monster* monster) = 0;		
	virtual void printSelectedClass() = 0;
	
	
	// 
	void printPlayerStatus();
	void levelUp();
	
	
	// === not done ===
	// getter
	string getPlayerName();
	string getPlayerJobname();
	
	int getPlayerLevel();
	int getPlayerHP();
	int getPlayerMP();
	int getPlayerPower();
	int getPlayerDefense();
	
	int getPlayerExp();
	int getPlayerMaxExp();
	
	// setter
	virtual bool setDamageAttackedFromMonster(int damage);
	
	bool setPlayerExp(int exp);
	
	

	virtual ~Player() {}

};
#endif