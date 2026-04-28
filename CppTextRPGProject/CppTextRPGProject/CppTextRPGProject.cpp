// CppTextRPGProject.cpp : Start Date: 4/28/2026



#include <iostream>
using namespace std;

void printStatus(string name, int stat[]);


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
    
    cout << "Enter HP and MP: "; cin >> stat[0] >> stat[1]; // In order to stay in same line, user has to press space after hp
    cout << "Enter Attack and Defense: "; cin >> stat[2] >> stat[3];// In order to stay in same line, user has to press space after hp
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