
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


bool DispensePotion(string name); // 재고 1 감소, 0이면 실패 메시지 출력하기
bool ReturnPotion(string name); // 재고 1 증가, MAX_STOCK(3) 초과 불가 처리하기
void GetStock(string name); // 현재 재고 반환하기
//
const int MAX_STOCK = 3;


vector<map<string, int>> allPotionStocks;

map<string, int> potionStock_;
//
int main() {

    // ex7

    potionStock_.insert(make_pair("HP Potion", 1));

    // 3개 초기화
    allPotionStocks.push_back(potionStock_);
    allPotionStocks.push_back(potionStock_);
    allPotionStocks.push_back(potionStock_);

    cout << "TESTING" << endl;

    cout << "allPotionStocks.size: " << allPotionStocks.size() << endl;

    //C++의 std::map은 인덱스(순서)를 통한 직접 접근(O(1))을 지원하지 않는다
    for (const auto& m : allPotionStocks) {
        for (auto const& item : m) {
            std::cout << item.first << ": " << item.second << "\n";
        }
        std::cout << "---" << "\n";
    }

    cout << "=== TESTING END ===" << endl;

	
    if (!DispensePotion("HP Potion"))
        cout << "-> Dispense failed: out of stock!\n";

    GetStock("");


    return 0;
}

bool DispensePotion(string name)
{
    cout << "DispensePotion" << endl;

    if (allPotionStocks.size() > 1)
        allPotionStocks.pop_back();
    else
        return false;

    return true;
}

bool ReturnPotion(string name) // 재고 1 증가, MAX_STOCK(3) 초과 불가 처리하기
{
    if (allPotionStocks.size() >= MAX_STOCK)
    {
        return false;
    }
    else
    {
        allPotionStocks.push_back(potionStock_);
        return true;
    }
}

void GetStock(string name)
{
    int count = 0;
    for (const auto& m : allPotionStocks)
    {
        for (auto const& item : m)
        {
            cout << item.first;
        }
        cout << " (stock: " << count << " )" << "\n";
        ++count;
    }

}