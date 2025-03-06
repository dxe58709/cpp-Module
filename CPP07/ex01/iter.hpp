#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printT(T str) {
    std::cout << str << ' ';
}

template <typename T, typename U>
void iter(T *arr, std::size_t len, U func) {
    if (!arr || !func) {
        std::cout << "Array pointer is NULL." << std::endl;
        return ;
    }
    if (len < 1) {
        std::cout << "Array length must be positive." << std::endl;
        return ;
    }
    for (std::size_t i = 0; i < len; i++)
        func(arr[i]);
}

//const
template <typename T, typename U>
void iter(const T *arr, std::size_t len, const U& func) {
    if (!arr || !func) {
        std::cout << "Array pointer is NULL." << std::endl;
        return ;
    }
    if (len < 1) {
        std::cout << "Array length must be positive." << std::endl;
        return ;
    }
    for (std::size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif
