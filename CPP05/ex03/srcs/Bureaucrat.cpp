#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	grade--;//範囲内なら減算
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) {
		throw GradeTooLowException();
	}
	grade++;//範囲内なら加算
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (os);
}
