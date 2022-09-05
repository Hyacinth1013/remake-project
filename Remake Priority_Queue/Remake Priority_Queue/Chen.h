#include <iostream>
#include <vector>
using namespace std;

namespace Chen
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};

	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue() :c() {}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: c(first, last)
		{
			int count = c.size();
			int root = ((count - 2) >> 1);
			for (; root >= 0; --root)
			{
				AdjustDown(root);
			}
		}

		void push(const T& data)
		{
			c.push_back(data);
			AdjustUp(c.size() - 1);
		}

		void pop()
		{
			if (empty()) return;
			swap(c.front(), c.back());
			c.pop_back();
			AdjustDown(0);
		}

		size_t size() const
		{
			return c.size();
		}

		bool empty() const
		{
			return c.empty();
		}

		const T& top() const
		{
			return c.front();
		}

	private:
		void AdjustUp(int child)
		{
			int parent = ((child - 1) >> 1);
			while (child)
			{
				if (Compare()(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
				{
					return;
				}
			}
		}

		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child < c.size())
			{
				if (child + 1 < c.size() && Compare()(c[child], c[child + 1]))
				{
					child += 1;
				}

				if (Compare()(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					return;
			}
		}

	private:
		Container c;
	};
}