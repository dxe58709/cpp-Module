#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute),  target(target) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return (name);
}

bool AForm::getIsSigned() const {
    return (isSigned);
}

int AForm::getGradeToSign() const {
	return (gradeToSign);
}

int AForm::getGradeToExecute() const {
    return (gradeToExecute);
}

//署名
void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	} else {
        isSigned = true;
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high for this Form!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low for this Form!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << " can be signed for " << form.getGradeToSign()
    << " grades and executed for " << form.getGradeToExecute() << "\n"
    << "Is Form Signed? -> " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}

const std::string &AForm::getTarget() const {
	return (target);
}