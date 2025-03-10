#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : N(N) {}//Nを初期化

Span::Span(const Span &other) {
	*this = other;
}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		N = other.N;
		vec = other.vec;
	}
	return (*this);
}
Span::~Span() {}
	
void	Span::addNumber(int num) {
	if (vec.size() >= N)
		throw std::out_of_range("Span is already full");
	vec.push_back(num);
}

void	Span::addNumbers(int begin, int end) {
	unsigned int range = static_cast<unsigned int>(end - begin);
	if (range + 1 > N)
		throw std::out_of_range("The range is too large to add.");
	for (int i = begin; i <= end && vec.size() < N; i++) {
		addNumber(i);
	}
}

int	Span::shortestSpan() {
	if (vec.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");
	std::vector<int> sort = vec;
	std::sort(sort.begin(), sort.end());
	int minSpan = INT_MAX;//最大値にしとくことでどの値がきても最小になる
	for (size_t i = 1; i < sort.size(); i++) {
		int diff = sort[i] - sort[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

int	Span::longestSpan() {
	if (vec.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");
	const int min = *std::min_element(vec.begin(), vec.end());
	const int max = *std::max_element(vec.begin(), vec.end());
	return (max - min);
}