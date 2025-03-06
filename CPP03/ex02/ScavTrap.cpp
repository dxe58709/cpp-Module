#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("") {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "Default ScavTrap constructed!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << name << " is out of energy or hit points and cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}