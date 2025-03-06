#include "FragTrap.hpp"

int main(void) {
	FragTrap object("John");
	std::cout << object;
	object.highFivesGuys();
	object.attack("Ken");
	object.takeDamage(50);
	std::cout << object;
	object.beRepaired(40);
	std::cout << object;
	object.takeDamage(150);
	std::cout << object;
	return (0);
}
