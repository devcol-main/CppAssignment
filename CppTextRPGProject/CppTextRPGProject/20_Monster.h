#pragma once

#include <iostream>

class Player;

using namespace std;

class Monster
{
    
protected:
    string name, dropItemName;
    int hp, power, defence, dropItemPrice;
    int expReward = 30;
    bool isDead = false;
public:
    Monster() = default;
    
    /*
    Monster(string name, 
        int hp, int power, int defence, 
        int dropItemPrice, string dropItemName) 
    : name(name), hp(hp), power(power), defence(defence), dropItemPrice(dropItemPrice), dropItemName(dropItemName) {}
    */
    // pure virtual func
    //void attack(Player* player);
    virtual void attack(Player* player);
    
    // get 
    string getMonsterName();
    string getDropItemName();
    
    int getHP();    
    int getPower();
    int getDefence();
    int getDropItemPrice();
    int getExpReward();
    
    bool getIsDead();
    
    //
    virtual bool setDamageAttackedFromPlayer(int damage);
    
    virtual ~Monster() = default; // virtual ~Monster() {}
    
    /*
    * = default;
    * 컴파일러 자동 구현: 프로그래머가 {} 안에 소멸자 내용을 직접 적지 않아도, 컴파일러가 기본적으로 제공하는 동작(멤버 변수들의 소멸자 호출 등)을 자동으로 정의합니다.
    * 효율성: 빈 소멸자(~Monster() {})를 직접 정의하는 것보다 = default를 사용하는 것이 컴파일러가 더 효율적인 코드를 생성할 수 있게 하여 최적화에 유리합니다.
     */
    
};
 
