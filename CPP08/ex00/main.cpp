#include "easyfind.hpp"
#include "easyfind.tpp"

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);
	lst.push_back(400);

	try {
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << " in vector." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator it = easyfind(lst, 500);
		std::cout << "Found: " << *it << " in list." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}