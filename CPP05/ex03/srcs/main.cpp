#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	intern;
	AForm*	presidential;
	AForm*	robotomy;
	AForm*	shrubbery;
	AForm*	form;

	presidential = intern.makeForm("Presidential Pardon", "Boss");
	robotomy = intern.makeForm("Robotomy request", "John");
	shrubbery = intern.makeForm("shrubbery Creation", "Mark");
	form = intern.makeForm("ABC", "Lisa");
	
	delete presidential;
	delete robotomy;
	delete shrubbery;
	delete form;
	return (0);
}
