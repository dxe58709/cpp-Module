#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type) {
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat assignment operator called!" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow!ฅ^•ω•^ฅ" << std::endl;
}
