#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <cstdlib>

enum ScalarType {
    _CHAR,
    _INT,
    _FLOAT,
    _DOUBLE,
    _ERROR
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

    public:
		static ScalarType getType(const std::string &literal);

		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);

		static void displayAsChar(const char c);
		static void displayAsInt(const int num);
		static void displayAsFloat(const float f);
		static void displayAsDouble(const double d);

        static void convert(const std::string &literal);
        static bool isPseudoLiterals(const std::string &literal);
        static void printPseudoLiterals(const ScalarType type, const std::string &literal);
};

#endif
