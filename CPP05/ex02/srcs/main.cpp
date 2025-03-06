#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void	testShrubForm()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	john("John", 145);
	ShrubberyCreationForm	form("Garden");
	try {
		boss.signForm(form);
		boss.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		john.signForm(form);
		john.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n";
}

static void	testRobotForm()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	john("John", 72);
	RobotomyRequestForm	form("Robot");

	srand(time(NULL));//現在時刻に基づく乱数の種[rand()%2]

	try {
		boss.signForm(form);
		boss.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		john.signForm(form);
		john.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n";
}

static void	testPresidentForm()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	john("John", 25);
	PresidentialPardonForm	form("presidential");
	try {
		boss.signForm(form);
		boss.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		john.signForm(form);
		john.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n";
}

int main()
{
	std::cout << "=====ShrubberyCreationForm=====" << std::endl;
	testShrubForm();
	std::cout << "=====RobotomyRequestForm=====" << std::endl;
	testRobotForm();
	std::cout << "=====PresidentialPardonForm=====" << std::endl;
	testPresidentForm();
	return 0;
}

/*
sign, excute
PresidentialPardonForm
25 5
RobotomyRequestForm
72 45
ShrubberyCreationForm
145 137
*/