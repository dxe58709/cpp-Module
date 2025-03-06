#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const {
	return (name);
}

bool Form::getIsSigned() const {
    return (isSigned);
}

int Form::getGradeToSign() const {
	return (gradeToSign);
}

int Form::getGradeToExecute() const {
    return (gradeToExecute);
}

//署名
void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	} else {
        isSigned = true;
    }
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high for this Form!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low for this Form!");
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << form.getName() << " can be signed for " << form.getGradeToSign()
    << " grades and executed for " << form.getGradeToExecute() << "\n"
    << "Is Form Signed? -> " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}