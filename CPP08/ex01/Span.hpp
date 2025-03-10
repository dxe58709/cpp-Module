#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <exception>
#include <climits> 

class Span {
	private:
		unsigned int N;
		std::vector<int> vec;//格納される整数のリスト
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
	
		void addNumber(int num);
		void addNumbers(int begin, int end);
		int shortestSpan();
		int longestSpan();
};
#endif
