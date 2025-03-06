#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

void checkDeepDog() {
	std::cout << BLUE << "------------------DOG-------------------" << RESET << std::endl;
	Dog* originalDog = new Dog();
	std::cout << BLUE << "-------" << RESET << std::endl;
	Dog* copyDog = new Dog(*originalDog);//deep copy

	//Dogオブジェクトが異なるメモリ位置にコピーされたかを確認（深いコピーであることを確認）
	std::cout << "\n[ originalDog ]" << YELLOW << " brain address: " << RESET << originalDog->getBrainAddress() << std::endl;
	std::cout << "[ copyDog ]" << YELLOW << " brain address: " << RESET << copyDog->getBrainAddress() << std::endl;

	//delete
	std::cout << MAGENTA << "\nDeleted: originalDog" << RESET << std::endl;
	delete originalDog;
	std::cout << MAGENTA << "Deleted: copyDog" << RESET << std::endl;
	delete copyDog;
}

void checkDeepCat() {
	std::cout << BLUE << "\n------------------CAT-------------------" << RESET << std::endl;
	Cat* originalCat = new Cat();
	std::cout << BLUE << "-------" << RESET << std::endl;
	Cat* copyCat = new Cat(*originalCat);//deep copy

	//Catオブジェクトが異なるメモリ位置にコピーされたかを確認（深いコピーであることを確認）
	std::cout << "\n[ originalCat ]" << YELLOW << " brain address: " << RESET << originalCat->getBrainAddress() << std::endl;
	std::cout << "[ copyCat ]" << YELLOW << " brain address: " << RESET << copyCat->getBrainAddress() << std::endl;

	//delete
	std::cout << MAGENTA << "\nDeleted: originalCat" << RESET << std::endl;
	delete originalCat;
	std::cout << MAGENTA << "Deleted: copyCat" << RESET << std::endl;
	delete copyCat;
}

int main() {
	const int arraySize = 6;
	Animal* animal[arraySize];

	std::cout << GREEN << "[ Creating animals ]" << RESET << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		if (i < arraySize / 2) {//前半はDog, 後半はCatがはいる
			animal[i] = new Dog();
			std::cout << GREEN << "-------------------------------------" << RESET << std::endl;
		} else {
			animal[i] = new Cat();
			std::cout << GREEN << "-------------------------------------" << RESET << std::endl;
		}
	}

	std::cout << GREEN << "\n[ Animal make sound ]" << RESET << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		std::cout << animal[i]->getType() << ": ";
		animal[i]->makeSound();
	}

	std::cout << YELLOW << "\n[ Deep Copy test ]" << RESET << std::endl;
	checkDeepDog();
	checkDeepCat();

	//delete memory
	std::cout << RED << "\n[ clean up ]" << RESET << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		delete animal[i];
		std::cout << RED << "-------------------------" << RESET << std::endl;
	}
	return 0;
}
