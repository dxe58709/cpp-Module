#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <algorithm>

class AForm;

struct FormName {
	int	id;
	const char *name;
};

class Intern {
	private:
		int	FormID(const std::string &name);
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);
};
#endif
