#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <climits>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		const std::string& getName() const;
		unsigned int getHit() const;
		unsigned int getEnergy() const;
		unsigned int getDamage() const;

		void setName(const std::string& newName);
		void setHit(unsigned int newHit);
		void setEnergy(unsigned int newEnergy);
		void setDamage(unsigned int newDamage);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream &os, const ClapTrap &object);

#endif