#include "chen.h"
using namespace std;

void TestVector1()
{
	chen::vector<int> first;
	chen::vector<int> second(4, 100);
	chen::vector<int> third(second.begin(), second.end());

	int myints[] = { 16,2,77,29 };
	chen::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents of fifth are:";
	for (chen::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	chen::vector<string> strV;
	strV.push_back("1111");
	strV.push_back("2222");
	strV.push_back("3333");
	strV.push_back("4444");
	for (size_t i = 0; i < strV.size(); ++i)
	{
		std::cout << strV[i] << " ";
	}
	std::cout << std::endl;
}

void PrintVector(chen::vector<int>& v)
{
	chen::vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

}

void TestVector2()
{
	//使用push_back插入4个数据
	chen::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.pop_back();
	PrintVector(v);

	chen::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector3()
{
	int a[] = { 1,2,3,4 };
	chen::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	auto pos = find(v.begin(), v.end(), 3);

	v.insert(pos, 30);
	PrintVector(v);

	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	PrintVector(v);
}

void TestVector4()
{
	int a[] = { 1,2,3,4 };
	chen::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	
	auto pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	cout << *pos << endl;

	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl;

	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);
	//	}
	//	++it;
	//}

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void TestVector5()
{
	int a[] = { 1,2,3,4 };
	chen::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	v.resize(3, 1);
	PrintVector(v);
}

int main()
{
	TestVector1();
	TestVector2();
	TestVector3();
	TestVector4();
	TestVector5();
	return 0;
}