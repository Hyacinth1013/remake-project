#include "Chen.h"

int main()
{
	Chen::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	cout << q.size() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}