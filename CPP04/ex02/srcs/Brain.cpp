#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++) {
	this->ideas[i] = other.ideas[i];//100個ideaをコピー
	}
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			this->ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assignment operator called!" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called!" << std::endl;
}