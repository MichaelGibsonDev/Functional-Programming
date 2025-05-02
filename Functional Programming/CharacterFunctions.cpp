#include "CharacterFunctions.h"
#include <iostream>

namespace CharacterFunctions
{
	Character CreateCharacter(const std::string& name, int health, int attackPower)
	{
		return Character{ name, health, attackPower, {} };
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
		int newHealth = character.health + healAmount;
		return Character{ character.name, newHealth, character.attackPower, character.inventory };
	}

	Character AddItem(const Character& character, const std::string& item)
	{
		Character updated = character;
		updated.inventory.push_back(item);
		return updated;
	}

	void DisplayInventory(const Character& character)
	{
		std::cout << "Name: " << character.name << "\n";
		std::cout << "Health: " << character.health << "\n";
	}
}