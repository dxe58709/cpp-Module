#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& newType);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		std::string getType() const;
		void setType(const std::string& newType);
		virtual void makeSound() const = 0;
};
#endif

//純粋仮装関数を含めることでインスタンス化をふせぐ