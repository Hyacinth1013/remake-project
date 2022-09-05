#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>

namespace Chen
{
	class string
	{
	public:
		typedef char* iterator;

	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s);
			this->swap(tmp);
		}

		string& operator=(string& s)
		{
			this->swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete _str;
				_str = nullptr;
			}
		}

		iterator begin() { return _str; };
		iterator end() { return _str + _size; };

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		void append(int num, const char* str)
		{
			while (str && num > 0)
			{
				if (_size == _capacity)
				{
					reserve(2 * _capacity);
				}
				_str[_size++] = *str;
				_str[_size] = '\0';
				--num;
			}
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		bool empty() const
		{
			return size() == 0;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
				{
					reserve(2 * _capacity);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);

				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		size_t find(char c, size_t pos = 0)
		{
			while (pos < _size)
			{
				if (c == _str[pos]) return pos + 1;
				++pos;
			}
			return pos + 1;
		}

		string& insert(size_t pos, char c)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size == _capacity)
			{
				size_t newcap = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newcap);
			}
			size_t it = _size + 1;
			while (it != pos)
			{
				_str[it] = _str[it - 1];
				--it;
			}
			_str[pos] = c;
			++_size;
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}