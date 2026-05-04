
#include <iostream>

#include <vector>
#include <map>
#include <string>

using namespace std;


// potion creation

struct PotionRecipe
{
    string potionName;
    string ingredientName1;
    string ingredientName2;
    map<string, int> ingredientMap;   
    
};

// =======================

void ShowAllRecipes(vector<PotionRecipe> allPotionInfo)
{
    for (int i = 0; i < allPotionInfo.size(); i++)
    {        
        //cout << i <<". " 
        cout << "-> " << allPotionInfo[i].potionName 
        << " (" << allPotionInfo[i].ingredientName1 << " x"<< allPotionInfo[i].ingredientMap[allPotionInfo[i].ingredientName1]
        << ", " << allPotionInfo[i].ingredientName2 << " x"<< allPotionInfo[i].ingredientMap[allPotionInfo[i].ingredientName2] << ")\n";
        //cout << allPotionInfo[i].ingredientMap["Herb"];
    }
    cout << endl;   
    
}

bool SearchByName(vector<PotionRecipe> allPotionInfo, string potionName)
{
    for (auto p : allPotionInfo)
    {
        if (p.potionName == potionName)
        {
            cout << "-> " << p.potionName 
            << " (" << p.ingredientName1 << " x" << p.ingredientMap[p.ingredientName1] 
            << ", " << p.ingredientName2 << " x" << p.ingredientMap[p.ingredientName2] << ")\n";
            
            return true;           
        } 
    }  

    
    cout << "No such potion\n";
    cout << "All potion names: ";
    for (auto p : allPotionInfo)
    {
        cout << p.potionName << "   ";
    }   
    
    cout << endl;
    
    return false;
}

bool SearchByIngredient(vector<PotionRecipe> allPotionInfo,string ingredientName)
{
    
    int numFound = 0;
    
    for (auto p : allPotionInfo)
    {
        if (p.ingredientMap.find(ingredientName) != p.ingredientMap.end())
        {
            cout << "-> " << p.potionName 
            << " (" << p.ingredientName1 << " x" << p.ingredientMap[p.ingredientName1] 
            << ", " << p.ingredientName2 << " x" << p.ingredientMap[p.ingredientName2] << ")\n";
            
            ++numFound;
        }        
    }
    
    cout << "Found " << numFound << "\n";
    
    if (0 == numFound)
    {
        cout << "No such ingredient\n";
        return false;   
    } 

    
    return true;    
}


// 대소문자 & 띄어쓰기 정확해야함 // 그거 무시하는거 구현 귀찮.
int main()
{   
    string const HPPOTION = "HPPotion";
    string const STAMINA_POTION = "StaminaPotion";
    
    string const HERB = "Herb";
    string const CLEAR_WATER = "Clear Water";
    string const BERRY = "Berry";
    
    //
    vector<PotionRecipe> allPotionInfo;  
    
    //
    PotionRecipe hpPotionRecipe;
    
    hpPotionRecipe.potionName = HPPOTION;
    
    hpPotionRecipe.ingredientName1 = HERB;
    hpPotionRecipe.ingredientMap[HERB] = 1;
    
    hpPotionRecipe.ingredientName2 = CLEAR_WATER;
    hpPotionRecipe.ingredientMap[CLEAR_WATER] = 1;
    
    //
    PotionRecipe staminaPotionRecipe;
    staminaPotionRecipe.potionName = STAMINA_POTION;
    staminaPotionRecipe.ingredientName1 = HERB;
    staminaPotionRecipe.ingredientMap[HERB] = 1;
    staminaPotionRecipe.ingredientName2 = BERRY;
    staminaPotionRecipe.ingredientMap[BERRY] = 1;   
    
    //
    allPotionInfo.push_back(hpPotionRecipe);
    allPotionInfo.push_back(staminaPotionRecipe);
    //
    
    
    
    //
    while (true)
    {
        //
        cout << "\n=== Potion Shop ===\n";
        cout << "1. Show all recipes\n";
        cout << "2. Search by potion name\n";
        cout << "3. Search by ingredient\n";
        cout << "0. Go back\n";
        
        //
        int potionShopChoice = 0;
        cout << "\nChoose: "; cin >> potionShopChoice;
        
        
        //
        if (0 == potionShopChoice)
        {
            cout << "0. Go back\n";
            break;
        }
        else if (1 == potionShopChoice)
        {
            //cout << "1. Show all recipes\n";
            ShowAllRecipes(allPotionInfo);
        }
        else if (2 == potionShopChoice)
        {
            string tempName;
            cout << "Search potion name: "; cin >> tempName;
            
            SearchByName(allPotionInfo,tempName);
            
        }
        else if (3 == potionShopChoice)
        {
            string tempName;
            cout << "Search ingredient: ";

            cin.ignore(); // 버퍼 비우기 (필수) // getline 전에 내가 cin 썻으니 써야한다.

            getline(cin, tempName); // inorder to include space need to use getline (#include <string>)             
            
            SearchByIngredient(allPotionInfo ,tempName);
            
            
        }
        else
        {
            cout << "!!Wrong choice\n";
        }
    }
        
    
    return 0;
}
