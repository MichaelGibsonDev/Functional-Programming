#pragma once
#include "Character.h"

namespace CharacterFunctions
{
	Character CreateCharacter(const std::string& name, int health, int attackPower);
	std::pair<Character, int>Attack(const Character& attacker, const Character& target);
	Character Heal(const Character& character, int healAmount);
	Character AddItem(const Character& character, const std::string& item);
	void DisplayInventory(const Character& character);
	void PrintStats(const Character& character);
}