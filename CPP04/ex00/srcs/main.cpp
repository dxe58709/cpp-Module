#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	// Animalの基本動作を確認
	std::cout << "[ Animal ]" << std::endl;
	const Animal* animal = new Animal();
	std::cout << "Type: " << animal->getType() << std::endl;
	animal->makeSound();
	delete animal;

	// Dogの基本動作を確認
	std::cout << "\n[ Dog ]" << std::endl;
	const Animal* dog = new Dog();
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;

	// Catの基本動作を確認
	std::cout << "\n[ Cat ]" << std::endl;
	const Animal* cat = new Cat();
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;

	// WrongAnimalとWrongCatの動作を確認
	std::cout << "\n[ WrongAnimal & WrongCat ]" << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << "Type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;
	std::cout << "----------------------------------" << std::endl;
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "Type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;

	return 0;
}