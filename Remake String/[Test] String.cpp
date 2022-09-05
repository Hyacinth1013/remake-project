#include "Chen.h"

void TestString()
{
	Chen::string s1("hello bit");
	s1.push_back(' ');
	s1.push_back('b');
	std::cout << s1.empty() << std::endl;
	//s1.append(12, "i");
	//s1 += 't';

	std::cout << s1.c_str() << std::endl;
	std::cout << s1.size() << std::endl;
	std::cout << s1.capacity() << std::endl;
	std::cout << s1.find('t') << std::endl;

	// 利用迭代器打印string中的元素
	Chen::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto ch : s1)
	{
		std::cout << ch << " ";
	}
	std::cout << std::endl;
}

int main()
{
	TestString();
	return 0;
}