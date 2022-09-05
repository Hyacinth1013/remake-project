#include "Chen.h"

int main()
{
	Chen::priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	cout << pq.top() << endl;
	cout << pq.size() << endl;
	pq.pop();
	cout << pq.top() << endl;
	cout << pq.size() << endl;
	return 0;
}