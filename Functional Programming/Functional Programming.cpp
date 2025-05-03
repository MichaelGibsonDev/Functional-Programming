// Functional Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "CharacterFunctions.h"
#include "Helper.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "Welcome to Bad RPG\n";

    std::cout << "=================================\n"; 

    Character hero = CharacterFunctions::CreateCharacter("Cloud", 100, 15);
    Character villain = CharacterFunctions::CreateCharacter("Sephiroth", 100, 15);

    //Add 5 times to the hero
    hero = CharacterFunctions::AddItem(hero, "Buster Sword");
    hero = CharacterFunctions::AddItem(hero, "Potion");
    hero = CharacterFunctions::AddItem(hero, "Phoenix Down");
    hero = CharacterFunctions::AddItem(hero, "Elixnir");
    hero = CharacterFunctions::AddItem(hero, "Limit Break");

    //Adding 3 items to the villian
    villain = CharacterFunctions::AddItem(villain, "Masamune");
    villain = CharacterFunctions::AddItem(villain, "Dark Cloak");
    villain = CharacterFunctions::AddItem(villain, "Black Materia");

    //Print stats and inventory
    CharacterFunctions::PrintStats(hero);
    CharacterFunctions::DisplayInventory(hero);

    CharacterFunctions::PrintStats(villain);
    CharacterFunctions::DisplayInventory(villain);

    //Main Battle
    while (hero.health > 0 && villain.health > 0)
    {
        bool attackFlip = Helper::CoinFlip();
        int healAmount = rand() % 5 + 1;

    if (attackFlip)
    {
        auto result = CharacterFunctions::Attack(hero, villain);
        villain = result.first;
        std::cout << hero.name << " attacked " << villain.name << " for " << result.second << " damage!\n";
        CharacterFunctions::PrintStats(villain);
    }
    else
    {
        auto result = CharacterFunctions::Attack(villain, hero);
        hero = result.first;
        std::cout << villain.name << " attacked " << hero.name << " for " << result.second << "damage!\n";
        CharacterFunctions::PrintStats(hero);
    }

    //Heal
    bool healFlip = Helper::CoinFlip();
    int healValue = rand() % 5 + 1;

    if (healFlip)
    {
        hero = CharacterFunctions::Heal(hero, healValue);
        std::cout << hero.name << " healed for " << healValue << " health.\n";
    }
    else
    {
        villain = CharacterFunctions::Heal(villain, healValue);
        std::cout << villain.name << " healed for " << healValue << " health.\n";
    }

    std::cout << "===============================\n";
    
    }
    CharacterFunctions::PrintStats(hero);
    CharacterFunctions::PrintStats(villain);

    std::cout << (hero.health > 0 ? hero.name : villain.name) << " is the winner\n";

    return 0;

}

