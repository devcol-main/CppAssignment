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
	int maxHP, maxMP;
	int exp = 0;
	int maxExp = 100;
	const int maxExpIncreaseAmount = 10;
	

public:
	
	Player(string name, JOB job, int hp, int mp, int power, int defense) :
	name(name), job(job), hp(hp), mp(mp), power(power), defence(defense)
	{
		level = 1;
		maxHP = hp;
		maxMP = mp;	
	}

	// pure virtual func	
	virtual void attack(Monster* monster) = 0;		
	virtual void printSelectedClass() = 0;
	
	
	// 
	void printStatus();
	void levelUp();
	
	
	// === not done ===
	// getter
	string getName();
	string getJobname();
	
	int getLevel();
	
	int getHP();
	int getMaxHP();
	
	int getMP();
	int getMaxMP();
	
	int getPower();
	int getDefense();
	
	int getExp();
	int getMaxExp();
	
	// setter
	virtual bool setDamageAttackedFromMonster(int damage);
	
	bool setExp(int exp);
	
	
	void setHP(int healHP);
	void setMP(int healMP);
	
	

	virtual ~Player() {}

};
#endif