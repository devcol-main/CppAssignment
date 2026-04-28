// CppTextRPGProject.cpp : Start Date: 4/28/2026

#include <iostream>
using namespace std;


//
void printStatus(string name, int stat[]);

//
enum STATS { HP, MP, Attack, Defense };

int main()
{

    //
    string heroName;
    const int SIZE = 4; int stat[SIZE] = { 0 }; //HP, MP, Attack, Defense;


    cout << "===========================================" << endl;
    cout << "   [Dungeon Escape Text RPG]" << endl;
    cout << "===========================================" << endl;    
    
    cout << "Enter your hero's name: "; cin >> heroName; // I puted in same line just to see easily
    cout << "\n";
    
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
    cout << "Created by in9 | Date: 2026/04/ " << endl;
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