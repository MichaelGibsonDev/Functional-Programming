#include "CharacterFunctions.h"
#include <iostream>

namespace CharacterFunctions
{
	Character CreateCharacter(const std::string& name, int health, int attackPower) {
		return Character(name, health, attackPower, {});
	}

	std::pair<Character, int> Attack(const Character& attacker, const Character& target)
	{
		int damage = attacker.attackPower;
		int newHealth = target.health - damage;
		newHealth = (newHealth < 0) ? 0 : newHealth;

		Character updatedTarget{ target.name, newHealth, target.attackPower, target.inventory };
		return { updatedTarget, damage };
	}

	Character Heal(const Character& character, int healAmount)
	{
		return Character{ character.name, character.health + healAmount, character.attackPower, character.inventory }; 
	}

	Character AddItem(const Character& character, const std::string& item)
	{
		std::vector<std::string> updatedInventory = character.inventory;
		updatedInventory.push_back(item);
		return Character{ character.name, character.health, character.attackPower, updatedInventory };
	}

	void DisplayInventory(const Character& character)
	{
		std::cout << character.name << "'s Inventory:\n";
		for (const std::string& item : character.inventory)
		{
			std::cout << "- " << item << "\n";
		}
	}

	void PrintStats(const Character& character)
	{
		std::cout << character.name << " | Health: " << character.health << " | Attack: " << character.attackPower << "\n";
	}
}
