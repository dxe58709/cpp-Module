#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"Formula\"" << std::endl;
		return 1;
	}
	try {
		RPN calculator;
		calculator.processRpn(argv[1]);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}