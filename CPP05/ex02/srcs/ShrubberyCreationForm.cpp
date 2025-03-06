#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::ofstream file((getTarget() + "_shrubbery").c_str());//std::string -> const char *

    if (!file) {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
        return;
    }
    std::cout << "Shrubbery created: " << getTarget() << "_shrubbery" << std::endl;

    file << "      /\\" << std::endl;
    file << "     /  \\" << std::endl;
    file << "    /    \\" << std::endl;
    file << "   /______\\" << std::endl;
    file << "     ||||" << std::endl;
    file << "     ||||" << std::endl;

    file.close();
}
