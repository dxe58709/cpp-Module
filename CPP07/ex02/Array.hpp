#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		unsigned int _size;
		T *data;
		inline void swap(Array &other);
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](size_t index);//unsigned intだと表せるメモリの量が小さい
		unsigned int size() const;
};

#endif
