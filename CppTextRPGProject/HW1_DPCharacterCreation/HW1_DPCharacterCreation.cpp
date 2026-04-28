/*
// HW1 캐릭터 생성 화면 (변수, 배열, 함수)

===========================================
   [ Dungeon Escape Text RPG ]
===========================================
Enter your hero's name: John

Enter HP and MP: 80 60
Enter Attack and Defense: 40 25

====================================
  John's Stats
====================================
HP: 80    MP: 60
Attack: 40    Defense: 25
====================================

**구현 항목**

- [ ]  `string` 타입으로 이름 입력 받기
- [ ]  `const int SIZE = 4`, `int stat[SIZE] = {0}` 배열 선언하기
- [ ]  `stat[0] = HP`, `stat[1] = MP`, `stat[2] = 공격력`, `stat[3] = 방어력` 순서로 사용하기
- [ ]  `cin`으로 스탯 2개씩 입력 받기
- [ ]  `void printStatus(string name, int stat[])` 함수 작성 후 호출하기

**주의할 점**

- 배열 인덱스 순서를 주석으로 남겨두면 이후 STEP에서 덜 헷갈립니다.

*/


#include <iostream>
using namespace std;

void printStatus(string name, int stat[]);


int main()
{

    //
    string heroName;
    const int SIZE = 4; int stat[SIZE] = { 0 };  //HP, MP, Attack, Defense;

    cout << "===========================================" << endl;
    cout << "   [Dungeon Escape Text RPG]" << endl;
    cout << "===========================================" << endl;

    cout << "Enter your hero's name: "; cin >> heroName; // I puted in same line just to see easily
    cout << "\n";

    //int stat[4]; //int HP, MP, Attack, Defense;
    cout << "Enter HP and MP: "; cin >> stat[0] >> stat[1]; // In order to stay in same line, user has to press space after hp
    cout << "Enter Attack and Defense: "; cin >> stat[2] >> stat[3];// In order to stay in same line, user has to press space after hp
    cout << "\n";
    
    printStatus(heroName, stat);

}



void printStatus(string name, int stat[])
{
    cout << "====================================" << endl;
    cout << "  ";cout << name << "s Stats" << endl;
    cout << "====================================" << endl;
    cout << "HP: " << stat[0];  cout << "    "; cout << "MP: " << stat[1]; cout << "\n";
    cout << "Attack: " << stat[2];  cout << "    "; cout << "Defense: " << stat[3]; cout << "\n";
    cout << "====================================" << endl;
}