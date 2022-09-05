#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _pPre(nullptr)
			, _pNext(nullptr)
			, _val(val)
		{}

		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}

		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{}

		T& operator*() { return _pNode->_val; }
		T* operator->() { return &(operator*()); }

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}

		Self& operator--();
		Self& operator--(int);

		bool operator!=(const Self& l) { return _pNode != l._pNode; }
		bool operator==(const Self& l) { return _pNode != l._pNode; }

		PNode _pNode;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
	public:
		list()
		{
			CreateHead();
		}

		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				push_back(value);
			}
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& l)
		{
			CreateHead();
			list<T> temp(l.cbegin(), l.cend());
			this->swap(temp);
		}

		list<T>& operator=(const list<T> l)
		{
			this->swap(l);
			return *this;
		}

		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		iterator begin() { return iterator(_pHead->_pNext); }
		iterator end() { return iterator(_pHead); }
		const_iterator cbegin() { return const_iterator(_pHead->_pNext); }
		const_iterator cend() { return const_iterator(_pHead); }

		size_t size() const
		{
			int _size = 0;
			PNode temp = _pHead;
			while (temp)
			{
				temp = temp->_pNext;
				++_size;
			}
			return _size;
		}

		bool empty() const
		{
			return _pHead == nullptr;
		}

		//T& front();
		//const T& front();
		//T& back();

		//const T& back() const;

		void push_back(const T& val) { insert(end(), val); }
		void pop_back() { erase(--end()); }
		void push_front(const T& val) { insert(begin(), val); }
		void pop_front() { erase(begin()); }

		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// 先将新节点插入
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}

		iterator erase(iterator pos)
		{
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;

			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;

			return iterator(pRet);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		void swap(list<T>& l)
		{
			PNode *temp = l->_pHead;
			l->_pHead = this->_pHead;
			this->_pHead = temp;
		}

	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}