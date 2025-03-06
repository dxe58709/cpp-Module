#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	protected:
		std::string target;
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string &target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const &execute) const = 0;
	
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		const std::string &getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif