#ifndef ARRAY_TPP
#define ARRAY_TPP

//空の配列を作成
template<typename T>
Array<T>::Array() : _size(0), data(NULL) {}

//n個の配列を作成（デフォルト初期化）
template<typename T>
Array<T>::Array(unsigned int n) : _size(n), data(new T[n]()) {}

template<typename T>
Array<T>::Array(const Array &other) : _size(other._size), data(new T[other._size]()) {
	for (unsigned int i = 0; i < _size; i++)
		data[i] = other.data[i];
}

//new が失敗したら、その時点で operator= は終了するので、元のデータが壊れない
//コピーしたオブジェクトがスコープを抜けると自動的にデストラクタが呼ばれて、古いデータが delete[] される
template<typename T>
inline void Array<T>::swap(Array &other) {
	size_t tmpSize = _size;
	_size = other._size;
	other._size = tmpSize;

	T* tmpData = data;
	data = other.data;
	other.data = tmpData;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		Array tmp(other);
		swap(tmp);
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {
	delete[] data;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::exception();
	return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

#endif
