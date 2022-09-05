#include "Chen.h"

void TestBSTree1()
{
	Chen::BSTree<char, int> tree;
	tree.Insert(make_pair('a', 1));
	tree.Insert(make_pair('b', 2));
	tree.Insert(make_pair('c', 3));
	tree.Insert(make_pair('d', 4));
	tree.Insert(make_pair('e', 5));
	tree.Insert(make_pair('f', 6));
	tree.InOrder();

	tree.Remove('a');
	tree.Remove('b');
	tree.Remove('c');
	tree.Remove('d');
	tree.Remove('e');
	tree.Remove('f');
	tree.Remove('g');
	tree.InOrder();
}

int main()
{
	TestBSTree1();
	return 0;
}