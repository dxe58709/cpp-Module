#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other): numStack(other.numStack) {}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->numStack = other.numStack;
	}
	return *this;
}

RPN::~RPN() {}

bool	RPN::processRpn(const char *argv) {
	std::string tokens = std::string(argv);
	for (std::string::iterator it = tokens.begin(); it != tokens.end(); ++it) {
		skipSpace(it);
		if (std::isdigit(*it)) {
			std::string::iterator next_it = it;
			++next_it;
			if (next_it != tokens.end() && std::isdigit(*next_it))// 次の文字も数値ならエラー
				throw std::runtime_error("Only single-digit numbers (0-9) are allowed");
			numStack.push(*it - '0');//数値ならpush, 文字を数値に変換
		} else if (isOperator(it)) {
			if (!calculate(it))
				throw std::runtime_error("Not numbers for operation");
		} else {
			if (it == tokens.end())//iteratorがtokenの終わりに達したら
				break;
			throw std::runtime_error("Invalid token");
		}
	}
	if (numStack.size() != 1) {//計算結果がスタックに一つだけ残るので１個じゃなかったらエラー
		throw std::runtime_error("Invalid RPN expression: incorrect number of operands");
	}
	std::cout << numStack.top() << std::endl;
	return true;
}

bool	RPN::isOperator(std::string::iterator it) const {
	return *it == '+' || *it == '-' || *it == '*' || *it == '/';
}

void	RPN::skipSpace(std::string::iterator &it) {
	while (*it == ' ')
		it++;
}

bool	RPN::calculate(std::string::iterator &it) {
	if (numStack.size() < 2)
		return false;
	
	int	num1 = numStack.top();
	numStack.pop();
	int	num2 = numStack.top();
	numStack.pop();
	switch (*it) {
		case '+':
			if ((num1 > 0 && num2 > INT_MAX - num1) || 
			(num1 < 0 && num2 < INT_MIN - num1))
				throw std::runtime_error("Addition overflow");
			numStack.push(num1 + num2);
			break;
		case '-':
			if ((num1 > 0 && num2 < INT_MIN + num1) || 
			(num1 < 0 && num2 > INT_MAX + num1))
				throw std::runtime_error("Subtraction overflow");
			numStack.push(num2 - num1);
			break;
		case '*':
			if (num2 > INT_MAX / num1 || num2 < INT_MIN / num1)
				throw std::runtime_error("Multiplication overflow");
			numStack.push(num1 * num2);
			break;
		case '/':
			if (num1 == 0)
				throw std::runtime_error("Division by zero");
			if (num2 == INT_MIN && num1 == -1)
				throw std::runtime_error("Division overflow");
			numStack.push(num2 / num1);
			break;
	}
	return true;
}