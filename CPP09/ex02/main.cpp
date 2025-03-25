#include "PmergeMe.hpp"

std::ostream& operator<<(std::ostream& os, char** args) {
	for (size_t i = 1; args[i] != NULL; ++i) {
		os << args[i] << " ";
	}
	return os;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Usage: ./PmergeMe [ positive integer sequence ]" << std::endl;
		return 1;
	}

	PmergeMe sort;
	/*vector*/
	std::vector<int> vec;
	try {
		vec = inputContainer<std::vector<int> >(argc, argv);
	} catch (std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	clock_t start = clock();
	sort.mergeInsertSort<std::vector<std::pair<int, int> > >(vec);
	clock_t end = clock();
	double elapsedVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;//us単位に変換

	/*deque*/
	std::deque<int> deque;
	try {
		deque = inputContainer<std::deque<int> >(argc, argv);
	} catch (std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	start = clock();
	sort.mergeInsertSort<std::vector<std::pair<int, int> > >(deque);
	end = clock();
	double elapsedDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	/*print*/
	std::cout << "Before:\t" << argv << std::endl;
	std::cout << "After:\t" << vec << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << vec.size() << " elements with std::vector :\t" \
		<< elapsedVec << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << deque.size() << " elements with std::deque :\t" \
		<< elapsedDeque << " us" << std::endl;
    return 0;
}