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

//
void printStartPage();
void enterStats();
void printStatus(string name, int stat[]);

//
int main()
{
    printStartPage();

}

//
void PrintStartPage()
{
    //cout <<  << endl;
    string heroName;
    int HP, MP, Attack, Defense;


    cout << "===========================================" << endl;
    cout << "   [Dungeon Escape Text RPG]" << endl;
    cout << "===========================================" << endl;
    cout << "Enter your hero's name: "; cin >> heroName; // I puted in same line just to see easily
    cout << "\n";
    
    cout << "Enter HP and MP: "; cin >> HP >> MP; // In order to stay in same line, user has to press space after hp
    cout << "Enter Attack and Defense: "; cin >> Attack >> Defense;// In order to stay in same line, user has to press space after hp
    cout << "\n";
    cout << "====================================" << endl;
    cout << "  ";cout << heroName << "s Stats" << endl;
    cout << "====================================" << endl;
    cout << "HP: " << HP;  cout << "    "; cout << "MP: " << MP; cout << "\n";
    cout << "Attack: " << Attack;  cout << "    "; cout << "Defense: " << Defense; cout << "\n";
    cout << "====================================" << endl;


    cout << "\n\n\n" << endl;
    cout << "Created by in9 | Date: " << endl;
}