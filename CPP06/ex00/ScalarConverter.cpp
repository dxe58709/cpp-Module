#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

//check type
bool	ScalarConverter::isChar(const std::string &str) {
	if (str.size() == 1 && (std::isprint(str[0]) || std::isspace(str[0])) && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string &str) {
	std::size_t  i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &str) {
	std::size_t	n = str.size();
	std::size_t	i = 0;
	std::size_t	decimalPoint = 0;

	if (str[n - 1] != 'f')
		return (false);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < n - 1; i++) {
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			decimalPoint += 1;
	}
	if (decimalPoint != 1)
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(const std::string &str) {
	std::size_t	n = str.size();
	std::size_t	i = 0;
	std::size_t	decimalPoint = 0;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < n; i++) {
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			decimalPoint += 1;
	}
	if (decimalPoint != 1)
		return (false);
	return (true);
}

ScalarType ScalarConverter::getType(const std::string &str) {
	if (isChar(str)) {
		return (_CHAR);
	} else if (isInt(str)) {
		return (_INT);
	} else if (isFloat(str)) {
		return (_FLOAT);
	} else if (isDouble(str)) {
		return (_DOUBLE);
	} else {
		return (_ERROR);
	}
}

//convert
void	ScalarConverter::displayAsChar(const char c) {
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::displayAsInt(const int num) {
	if (std::numeric_limits<char>::min() <= num &&
		num <= std::numeric_limits<char>::max() && std::isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
    	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void	ScalarConverter::displayAsFloat(const float f) {
	if (std::numeric_limits<char>::min() <= f &&
			f <= std::numeric_limits<char>::max() && std::isprint(f))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << static_cast<float>(f) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void	ScalarConverter::displayAsDouble(const double d) {
	if (std::numeric_limits<char>::min() <= d &&
			d <= std::numeric_limits<char>::max() && std::isprint(d))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
}

bool	ScalarConverter::isPseudoLiterals(const std::string &literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
			literal == "-inff" || literal == "+inff" || literal == "nanf") {
		return (true);
	} else {
		return (false);
	}
}

void	ScalarConverter::printPseudoLiterals(const ScalarType type, const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == _FLOAT) {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	} else if (type == _DOUBLE) {
		std::cout << "float: " << literal + "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &literal) {
	ScalarType type = getType(literal);

	if (type == _CHAR) {
		displayAsChar(literal[0]);
	} else if (type == _INT) {
		try {
			displayAsInt(std::atoi(literal.c_str()));
		} catch (const std::out_of_range &e) {
			std::cout << "Error: Number out of range for int conversion." << std::endl;
		}
	} else if (type == _FLOAT) {
		if (isPseudoLiterals(literal)) {
			printPseudoLiterals(type, literal);
		} else {
			try {
				displayAsFloat(static_cast<float>(std::atof(literal.c_str())));
			} catch (const std::out_of_range &e) {
				std::cout << "Error: Number out of range for float conversion." << std::endl;
			}
		}
	} else if (type == _DOUBLE) {
		if (isPseudoLiterals(literal)) {
			printPseudoLiterals(type, literal);
		} else {
			try {
				displayAsDouble(std::atof(literal.c_str()));
			} catch (const std::out_of_range &e) {
				std::cout << "Error: Number out of range for double conversion." << std::endl;
			}
		}
	} else {
		std::cout << "Please input char, int, float, or double" << std::endl;
	}
}