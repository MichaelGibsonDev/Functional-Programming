#pragma once
#include <string>
#include <vector>

struct Character
{
	std::string name;
	int health;
	int attackPower;
	std::vector<std::string> inventory;

	Character(const std::string& n, int h, int a, const std::vector<std::string>& i)
		: name(n), health(h), attackPower(a), inventory(i) {
	} 

};