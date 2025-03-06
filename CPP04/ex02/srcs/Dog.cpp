#include "Dog.hpp"

Dog::Dog() {
	brain = new Brain();
	type = "Dog";
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.type) {
	brain = new Brain(*other.brain); //Deep copy
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain; //delete current brain object
		brain = new Brain(*other.brain); //コピー元のBrainオブジェクトをDeep copy
	}
	std::cout << "Dog assignment operator called!" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called!" << std::endl;
}

Brain* Dog::getBrainAddress() const {
	return brain;
}

void Dog::makeSound() const {
	std::cout << "bowwow!(U ･ω･)" << std::endl;
}
