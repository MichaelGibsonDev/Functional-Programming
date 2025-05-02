#pragma once
#include <string>
#include <vector>

struct Character
{
	const std::string name;
	int health;
	int attackPower;
	std::vector<std::string> inventory;
};