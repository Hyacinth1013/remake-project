#include "bit.h"

template<class T>
void PrintList(const bit::list<T> &l)
{
	auto it = l.cbegin();
	while (it != l.cend())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void TestList1()
{
	bit::list<int> l1;
	bit::list<int> l2(10, 5);
	PrintList(l2);

	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	bit::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);

	bit::list<int>l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
}

void TestList2()
{
	bit::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	PrintList(l);

	l.pop_back();
	l.pop_back();
	PrintList(l);

	l.pop_back();
	std::cout << l.size() << std::endl;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	PrintList(l);

	l.pop_front();
	l.pop_front();
	PrintList(l);

	l.pop_front();
	std::cout << l.size() << std::endl;
}

void TestList3()
{
	int array[] = { 1,2,3,4,5 };
	bit::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto pos = l.begin();
	l.insert(l.begin(), 0);
	PrintList(l);

	++pos;
	l.insert(pos, 2);
	PrintList(l);

	l.erase(l.begin());
	l.erase(pos);
	PrintList(l);

	// std::cout << *pos << std::endl;

	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	std::cout << l.size() << std::endl;
}