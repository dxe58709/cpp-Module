#include "ScavTrap.hpp"

int main(void) {
	ScavTrap object("John");
	std::cout << object;
	object.guardGate();
	object.attack("Ken");
	object.takeDamage(100);
	std::cout << object;
	object.beRepaired(10);
	std::cout << object;
	return (0);
}
