#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::cout << "<<<Drilling noises>>>" << std::endl;
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << getTarget() << " has not been robotomized..." << std::endl;
}
