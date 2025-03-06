#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default ClapTrap constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
	if (name.empty()) {
		std::cout << "ClapTrap constructed!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " constructed!" << std::endl;
	}
}

//コピーコンストラクタ： ClapTrap clap2(clap1);
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {}

//コピー演算子： ClapTrap clap1 = clap2;
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}

	return (*this);
}

ClapTrap::~ClapTrap() {
	if (name.empty()) {
		std::cout << "ClapTrap destructed!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " destructed!" << std::endl;
	}	
}

//getName
const std::string& ClapTrap::getName() const {
	return (name);
}

unsigned int ClapTrap::getHit() const {
	return (hitPoints);
}

unsigned int ClapTrap::getEnergy() const {
	return (energyPoints);
}

unsigned int ClapTrap::getDamage() const {
	return (attackDamage);
}

//setName
void ClapTrap::setName(const std::string& newName) {
	name = newName;
}

void ClapTrap::setHit(unsigned int newHit) {
	hitPoints = newHit;
}

void ClapTrap::setEnergy(unsigned int newEnergy) {
	energyPoints = newEnergy;
}

void ClapTrap::setDamage(unsigned int newDamage) {
	attackDamage = newDamage;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " is out of energy or hit points and cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		hitPoints = (amount > hitPoints) ? 0 : (hitPoints - amount);
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		unsigned int RecoveryAmount = (UINT_MAX - hitPoints < amount) ? (UINT_MAX - hitPoints) : amount;
		std::cout << "ClapTrap " << name << " repaired " << RecoveryAmount << " hit points!" << std::endl;
		hitPoints += RecoveryAmount;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " is out of energy or hit points and cannot repair itself!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const ClapTrap &object) {
	os << "Name: " << object.getName() << std::endl;
	os << "Hit: " << object.getHit() << std::endl;
	os << "Energy: " << object.getEnergy() << std::endl;
	os << "Damage: " << object.getDamage() << std::endl;
	return (os);
}
