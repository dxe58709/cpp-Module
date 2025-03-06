#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return (*this);
}

Intern::~Intern() {}

int	Intern::FormID(const std::string &name) {
	FormName forms[] = {
		{1, "presidential pardon"},
		{2, "robotomy request"},
		{3, "shrubbery creation"}
	};
	for (int i = 0; i < 3; ++i) {
		if (name == forms[i].name) {
			return (forms[i].id);
		}
	}
	return (-1);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	std::string lowerName = name;
	transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);//小文字に変換してフォーム名を比較

	switch (FormID(lowerName)) {
		case 1:
			std::cout << "Intern creates " << name << " !" << std::endl;
			return (new PresidentialPardonForm(target));
		case 2:
			std::cout << "Intern creates " << name << " !" << std::endl;
			return (new RobotomyRequestForm(target));
		case 3:
			std::cout << "Intern creates " << name << " !" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << name << " form doesn't exist!" << std::endl;
			return (NULL);
	}
}