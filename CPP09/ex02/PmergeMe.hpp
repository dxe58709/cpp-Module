#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <cerrno>
#include <iomanip>
#include <ctime>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        struct PairCompare {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
                return a.first < b.first;
            }
        };
        
        template <typename PairContainer, typename Container>
        void mergeInsertSort(Container &arr);
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}
	return os;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::deque<T>& deq) {
	for (size_t i = 0; i < deq.size(); ++i) {
		os << deq[i] << " ";
	}
	return os;
}

template <typename Iterator>
bool    checkSorted(Iterator first, Iterator last) {
    if (first == last)//コンテナが空の場合
        return true;
    
    Iterator next = first;
    ++next;
    while (next != last) {
        if (*first > *next)//直前の要素が次の要素より大きければソートされていない
            return false;
        ++first;
        ++next;
    }
    return true;
}

template<typename Container>
Container inputContainer(int argc, char **argv) {
    Container container;
    if (argc > 10000)
        throw std::invalid_argument("too many args: max 10000");
    for (int i = 1; i < argc; i++) {
        errno = 0;
        char *nonDigitPtr;
        long l = std::strtol(argv[i], &nonDigitPtr, 10);//文字列av[i]を10進数の整数(long型)に変換

        if (*nonDigitPtr != '\0' || errno == ERANGE || errno == EINVAL || \
            strlen(argv[i]) > 11 || l <= 0 || l > 2147483647) {
            throw std::invalid_argument("Invalid Argument");
        }
        int value = (int)l;
        if (std::find(container.begin(), container.end(), value) != container.end())//valueがすでに存在するか
			throw std::invalid_argument("Duplicate value detected");
        container.push_back((int)l);
    }
    if (checkSorted(container.begin(), container.end())) {
		throw std::invalid_argument("Arguments are already sorted");
	}
	return container;
}

/* make_pair : 2つの要素のペアを作成 
PairContainer はペアを格納するコンテナ（std::vector<std::pair<int, int>>）
Container は元データを格納するコンテナ（std::vector<int>）
*/
template <typename PairContainer, typename Container>
void makePairs(PairContainer &pairs, const Container &arr) {
    for (typename Container::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        int first = *it;
        ++it;
        if (it == arr.end())
            break;
        int next = *it;
        if (first < next)
            std::swap(first, next);
        pairs.push_back(std::make_pair(first, next));
    }
}

/* mergeSort */
template <typename PairContainer, typename Container>
void mergeSort(PairContainer &pairs, typename Container::value_type lastElement, bool hasLastElement, \
                Container &large,   Container &small) {
    std::sort(pairs.begin(), pairs.end(), PmergeMe::PairCompare());//数字の大きい方でソートされる

    for (typename PairContainer::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        large.push_back(it->first);
        small.push_back(it->second);
    }
    if (hasLastElement)
        small.push_back(lastElement);
}

/* jacobsthal */
template <typename Container>
Container generateJacobsthalNumbers(int n) {
    Container jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

template <typename Container>
Container jacobsthal(int n) {
    // Jacobsthal数を生成する関数（generateJacobsthalNumbers）を呼び出し、結果をコンテナに格納
    Container prevJacob = generateJacobsthalNumbers<Container>(n);  
    Container curJacob;
    
    for (size_t i = 2; i < prevJacob.size(); ++i) {
        for (int pos = prevJacob[i]; pos > prevJacob[i-1]; --pos) {
            if (pos <= n) {
                curJacob.push_back(pos);  // 要素を挿入
            }
        }
    }
    return curJacob;  // 挿入順序を格納したコンテナを返す
}

template <typename Container>
void BinaryInsertion(Container &large, const Container &small) {
    if (small.empty())
        return;

    Container insertSequence = jacobsthal<Container>(small.size());  // jacobsthal関数で挿入順序を取得

    typename Container::iterator insertPos = std::lower_bound(large.begin(), large.end(), small[0]);
    large.insert(insertPos, small[0]);

    // Jacobsthal数に基づいて残りの要素を挿入
    for (typename Container::iterator it = insertSequence.begin(); it != insertSequence.end(); ++it) {
        if (*it > 0 && static_cast<size_t>(*it - 1) < small.size()) {
            typename Container::iterator insertPos = std::lower_bound(large.begin(), large.end(), small[*it - 1]);
            large.insert(insertPos, small[*it - 1]);
        }
    }
}

template <typename PairContainer, typename Container>
void PmergeMe::mergeInsertSort(Container &arr) {
    PairContainer pairs;

    if (arr.size() <= 1)
        return;
    typename Container::value_type lastElement = 0;
    bool hasLastElement = false;
    if (arr.size() % 2 != 0) {//奇数だったら
        typename Container::iterator last = arr.end();
        --last;
        lastElement = *last;
        hasLastElement = true;
    }
    makePairs(pairs, arr);
    Container large;
    Container small;
    mergeSort(pairs, lastElement, hasLastElement, large, small);
    BinaryInsertion(large, small);

    arr = large;
} 

#endif