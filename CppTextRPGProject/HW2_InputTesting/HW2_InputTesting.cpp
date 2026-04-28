// HW2_InputTesting.cpp
// STEP 2 - 입력 유효성 검사 (while, 조건문)

/*

Enter HP and MP: 30 80
HP or MP is too low. Try again.
Enter HP and MP: 80 60
Enter Attack and Defense: -5 25
Attack or Defense is too low. Try again.
Enter Attack and Defense: 40 25

**구현 항목**

- [ ]  HP/MP 입력 블록을 `while(true)`로 감싸기
- [ ]  HP와 MP가 모두 50보다 클 때만 `break`로 입력 루프 탈출하기
- [ ]  공격력/방어력도 동일하게 반복 입력 구현하기

**주의할 점**

- `while` 안에서 입력을 다시 받지 않으면 무한 루프가 됩니다.

*/


#include <iostream>
using namespace std;


//
void printStatus(string name, int stat[]);

//
enum STATS { HP, MP, Attack, Defense };

int main()
{
    //
    cout << "   [HW2_InputTesting]" << endl;
    //



    //
    string heroName;
    const int SIZE = 4; int stat[SIZE] = { 0 }; //HP, MP, Attack, Defense;   
    

    while (true)
    {
        cout << "Enter HP and MP: "; cin >> stat[HP] >> stat[MP]; // In order to stay in same line, user has to press space after hp
        
        // HP와 MP가 모두 50보다 클 때만 break로 입력 루프 탈출하기
        if (stat[HP] > 50 && stat[MP] > 50)
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
        cout << "Enter Attack and Defense: "; cin >> stat[Attack] >> stat[Defense]; // In order to stay in same line, user has to press space after hp

        // Attack, Defense가 모두 50보다 클 때만 break로 입력 루프 탈출하기
        if (stat[Attack] > 50 && stat[Defense] > 50)
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
    cout << "\n\n\n" << endl;
    cout << "Created by in9 | Date: " << endl;
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