#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat john("John", 42);
		std::cout << john << std::endl;

		john.incrementGrade();
		std::cout << john << std::endl;

		john.decrementGrade();
		std::cout << john << std::endl;

		Bureaucrat ken("Ken", 151); //グレードが150より下はないため例外発生
        std::cout << ken << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
        Bureaucrat jane("Jane", 1);
        std::cout << jane << std::endl;

        jane.incrementGrade(); //グレードが1より上になれないため例外発生
		std::cout << jane << std::endl;

		jane.decrementGrade();
		std::cout << jane << std::endl;
    }
    catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	return 0;
}