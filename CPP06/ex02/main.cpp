#include "Base.hpp"

int main() {
	std::srand(std::time(0));
	Base *b = generate();

	std::cout << "Identify by pointer: ";
    identify(b);
	std::cout << "Identify by reference: ";
    identify(*b);
	return (0);
}
