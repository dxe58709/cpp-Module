#include "Span.hpp"

void testLargeSpan() {
	std::cout << "===== Testing Large Span with 10,000+ Numbers =====" << std::endl;
	Span sp(10000);
	try {
		sp.addNumbers(1, 10000);
		int shortest = sp.shortestSpan();
		std::cout << "Shortest Span: " << shortest << std::endl;
		int longest = sp.longestSpan();
		std::cout << "Longest Span: " << longest << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;	
	}
	testLargeSpan();
	return 0;
}