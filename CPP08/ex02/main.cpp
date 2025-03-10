#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;//17

	mstack.pop();//delete 17

	std::cout << mstack.size() << std::endl;//1

	mstack.push(3);//[5,3]
	mstack.push(5);//[5,3,5]
	mstack.push(737);//[5,3,5,737]
	mstack.push(0);//[5,3,5,737,0]

	MutantStack<int>::iterator it = mstack.begin();//5
	MutantStack<int>::iterator ite = mstack.end();//最後の次の位置(0の次)

	++it;//3
	--it;//5(一番目の要素)
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Stack contents:" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return 0;
}

/*
#include <list>

int main()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::list<int> s(mstack);
	std::cout << "Stack contents:" << std::endl;
	while (!s.empty())
	{
		std::cout << s.back() << std::endl;
		s.pop_back();
	}
	return 0;
}
*/