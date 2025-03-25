#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <climits>
#include <stack>

class RPN {
	private:
		std::stack<int> numStack;
		bool	isOperator(std::string::iterator it) const;
		void	skipSpace(std::string::iterator &it);
		bool	calculate(std::string::iterator &it);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		bool	processRpn(const char *argv);
};

#endif