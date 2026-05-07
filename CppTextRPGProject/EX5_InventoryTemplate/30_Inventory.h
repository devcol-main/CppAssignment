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

// 
// T* pItems_, int capacity_, int size_

template<typename T>

// 그냥 벡터로 짠게 훨씬 편한데... 이거 그냥 공부하라고 쓰는 거였다...
class Inventory
{
    
    // these should be in private 근데 작은 프로젝트이고 귀찮으니 이렇게 ㄱㄱ
public:
    
    // 원래 아이템 클래스 새로 만들어야 하지만 요구 안했고 귀찮으니 ㄱㄱ
    
    //
     /*
    vector<ItemInfo> items;
    
    int currentMaxInventorySize = 10;
    */
    
    //
    T* pItems_; 
    
    int capacity_;
    int size_;
    
    //AddItem, RemoveLastItem, 
    
    
    // Shallow copy 얕은 복사    
    Inventory(int capacity) : capacity_(capacity), size_(0)
    {       
        
        pItems_ = new T[capacity];
    }
    
    
    // Deep copy 깊은 복사
    // 클래스이름(const 클래스이름 &rhs);
    Inventory(const Inventory& other) : capacity_(other.capacity_), size_(other.size_)
    {        
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; i++)
        {
            pItems_[i] = other.pItems_[i];
        }
    }
    
    
    void AddItem(const T& item)
    {
        if (size_ < capacity_)
        {
            pItems_[size_++] = item;
        }
    }
    
    void RemoveLastItem()
    {
        if (size_ > 0)
        {
            size_--;
        }
    }
    
    void RemoveSelectedItem(int index)
    {
        if (index >= 0 && index < size_)
        {
            // 원소 삭제 후 뒤 원소들을 앞으로 땡김
            for (int i = index; i < size_ - 1; i++)
            {
                pItems_[i] = pItems_[i + 1];
            }
            // 뒤에가 하나 비니깐 사이즈 줄이기
            size_--;
        }       
    }
    
    // std::sort(pItems_, pItems_ + size_, compareByPrice)
    
    bool compareByPrice(const ItemInfo& a, const ItemInfo& b)
    {
        return a.itemPrice > b.itemPrice;
    }
    
    void SortItems()
    {
        sort(pItems_, pItems_ + size_, compareByPrice);
    }
    
    void PrintAllItems() const  // 읽기 전용 함수
    {       
        //cout << "PRINTALLITEMS " << endl;

        for (int i = 0; i < size_; i++)
        {
            pItems_[i].PrintInfo();
        }
        
        //cout << "===== PRINTALLITEMS END =====" <<endl;
        
        // my old inventory
        /*cout << "AUTO items" <<endl;
        for (auto i : items)
        {
            i.PrintInfo();
        }
        cout << "===== AUTO END =====" <<endl;*/
    }
    
    void GetSize()
    {
        cout << size_ << endl;
    }
    void GetCapacity()
    {
        cout << capacity_ << endl;
    }   
    
    
    ~Inventory()
    {
       delete[] pItems_; 
    }
    
};
