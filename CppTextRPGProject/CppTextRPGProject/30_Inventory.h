#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include "10_Player.h"
#include  "90_GlobalVariable.h"

using namespace std;


struct ItemInfo
{
    
    string itemName;
    int itemPrice;
    void PrintInfo() const
    {
        cout << itemName << " (" << itemPrice << "G)\n";
    }
};


class Inventory
{
    
    // these should be in private 근데 작은 프로젝트이고 귀찮으니 이렇게 ㄱㄱ
public:
    
    // 원래 아이템 클래스 새로 만들어야 하지만 요구 안했고 귀찮으니 ㄱㄱ
    
    //
    
    vector<ItemInfo> items; 
    //ItemInfo itemInfo;
    int currentMaxInventorySize = 10;
    
    
    bool UseItem(int itemIndex);
};
