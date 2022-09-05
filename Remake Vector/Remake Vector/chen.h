#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>

namespace chen
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin() { return _start; };
		iterator end() { return _finish; };
		const_iterator cbegin() { return _start; };
		const_iterator cend() { return _finish; };

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		vector(int n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + oldSize;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			iterator it = _finish;
			iterator finish = _start + n;
			while (it != finish)
			{
				*it = value;
				++it;
			}
		}

		T& operator[](size_t pos) { return _start[pos]; };
		const T& operator[](size_t pos) const { return _start[pos]; };

		void push_back(const T& val) { insert(end(), val); };
		void pop_back() { erase(end()); };

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		iterator find(iterator first, iterator last, T val)
		{
			while (first != last)
			{
				if (*first == val) return first;
				++first;
			}
			return last;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t _size = size();
				size_t newCapacity = (capacity() == 0) ? 1 : capacity() * 2;
				reserve(newCapacity);
				pos = _start + _size;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos <= _finish);
			iterator left = pos;
			iterator right = _finish;
			while (left < right)
			{
				*left = *(left + 1);
				++left;
			}
			--_finish;
			return pos;
		}

		size_t size() const { return _finish - _start; };
		size_t capacity() const { return _endOfStorage - _start; };
		bool empty() const { return _start == _finish; };
	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};
}