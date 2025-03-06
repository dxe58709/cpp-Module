#include "Array.hpp"
#include "Array.tpp"

int main() {
	Array<int> emptyArray;
	std::cout << "emptyArray size: " << emptyArray.size() << std::endl;
	std::cout << "----------------------" << std::endl;

	Array<int> arr1(5);
	Array<int> arr2 = arr1;//assigment operator
	arr1[0] = 10;

	std::cout << "arr1[0]: " << arr1[0] << std::endl;
	std::cout << "arr2[0]: " << arr2[0] << std::endl;
	std::cout << "----------------------" << std::endl;

	Array<int> arr3(arr1);//copy constructa
	arr1[1] = 42;
	std::cout << "arr1[1]: " << arr1[1] << std::endl;
	std::cout << "arr3[1]: " << arr3[1] << std::endl; 
	std::cout << "----------------------" << std::endl;

	try {
		std::cout << arr1[10] << std::endl;//範囲外アクセス
	} catch (const std::exception &e) {
		std::cerr << "Out of range access detected!" << std::endl;
	}


	return (0);
}