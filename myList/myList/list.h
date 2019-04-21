#define _CRT_SECURE_NO_WARNINGS 1
namespace myList
{
	////List�Ľ����
	template<class T>
	class ListNode
	{
	public:
		ListNode(const T& val = T())
			:_data(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
		T _data;
		ListNode<T>* _next;
		ListNode<T>* _prev;
	};

	//List�ĵ�����
	template<class T, class Ref, class Ptr>		//
	class ListIterator
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
		PNode _node;

		ListIterator(PNode node)
			:_node(node)
		{}

		//*iterator
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}

		//++iterator _node->_next
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& lit)
		{
			return _node != lit._node;
		}

		bool operator==(const Self& lit)
		{
			return _node == lit._node;
		}
	};

	//List�ķ��������
	template<class T, class Ref, class Ptr, class Iterator>	//���ε�ʱ�����ģ�����ݲ�������
	class ListReverseIterator
	{
		typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
	public:
		ListReverseIterator(const Iterator& it)
			:_it(it)
		{}

		ListReverseIterator(const Self& s)
			:_it(s._it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);	//����������ͷ����������ǰ��ġ������������ǰλ�õ���һ��λ��������������ĵ�ǰλ�á�
		}

		Ptr operator->()
		{
			return &operator*();
		}

		//ǰ��++�������������++���������������--
		Self& operator++()	//ǰ�÷�������
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Iterator temp(_it);		//��������������Ĺ��췽��
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Iterator temp(_it);
			++_it;
			return temp;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

	private:
		Iterator _it;		//��װ������������ײ���õ���const�ͷ�const�����������
	};

	template<class T>
	class List
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		typedef ListReverseIterator<T, const T&, const T*, iterator> reverse_iterator;
		typedef ListReverseIterator<T, const T&, const T*, const_iterator> const_reverse_iterator;
		List()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		List(int n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; ++i){
				PushBack(value);
			}
		}

		template<class Iterator>
		List(Iterator first, Iterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last){
				PushBack(*first);
				++first;
			}
		}

		List(const List<T>& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			List<T> temp(l.cbegin(), l.cend());
			swap(_head, temp._head);
		}

		List<T>& operator=(List<T> l)	//�ִ���д������ֵ����ù��죬��������ʱ����������this��ָ��ָ��
			//��ʱ�����������������
		{
			swap(_head, l._head);
			return *this;
		}

		~List()
		{
			if (_head)
			{
				PNode cur = _head->_next;
				while (cur != _head)
				{
					PNode next = cur->_next;
					delete cur;
					cur = next;
				}
				delete _head;
				_head = nullptr;
			}
		}

		////////////////////////////////////////////////////////////////////
		//������
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator cbegin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator cend() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());	//end()�����൱����iterator(_head)Ȼ����÷���������Ĺ��캯��
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator crbegin() const
		{
			return const_reverse_iterator(cend());
		}

		const_reverse_iterator crend() const
		{
			return const_reverse_iterator(cbegin());
		}

		///////////////////////////////////////////////////////////////////////
		//List Access
		T& Front()
		{
			return _head->_next->_data;
		}

		const T& Front() const
		{
			return _head->_next->_data;
		}

		T& Back()
		{
			return _head->_prev->_data;
		}

		const T& Back() const
		{
			return _head->_prev->_data;
		}

		/////////////////////////////////////////////////////////////////////////////
		//List Modify
		void PushBack(const T& val)
		{
			PNode newNode = new Node(val);
			PNode prev = _head->_prev;
			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = _head;
			_head->_prev = newNode;
		}

		void PopBack()
		{
			//�ҵ�Ҫɾ���Ľ�㣬Ҳ����ͷ����ǰһ���������һ�����
			PNode del = _head->_prev;
			//ֻ��һ��ͷ��㲻��ɾ��
			if (del != _head){
				_head->_prev = del->_prev;
				del->_prev->_next = _head;
				delete del;
			}
		}
		void PushFront(const T& val)
		{
			PNode newnode = new Node(val);
			newnode->_prev = _head;
			newnode->_next = _head->_next;
			_head->_next->_prev = newnode;
			_head->_next = newnode;
		}
		void PopFront()
		{
			PNode cur = _head->_next;
			if (cur != _head){
				_head->_next = cur->_next;
				cur->_next->_prev = _head;
				delete cur;
			}
		}
		//��posλ��ǰ����ֵΪval�Ľ��
		iterator Insert(iterator pos, const T& val)
		{
			PNode newnode = new Node(val);
			//pos�ǵ�������Ҫȡ��posλ�õĽ��
			PNode cur = pos._node;
			newnode->_next = cur;
			newnode->_prev = cur->_prev;
			newnode->_prev->_next = newnode;
			cur->_prev = newnode;

			return iterator(newnode);
		}
		//ɾ��posλ�õĽ�㣬���ظý�����һ��λ��
		iterator Erase(iterator pos)
		{
			//����posλ�õĽ���Լ�posλ�ý���ǰһ�����ͺ�һ�����
			PNode del = pos._node;
			PNode prev = del->_prev;
			PNode next = del->_next;
			//ע�ⲻ��ɾ��ͷ���
			if (del != _head){
				prev->_next = next;
				next->_prev = prev;

				delete del;
				del = nullptr;

				//���µ�����
				pos = iterator(next);
			}
			return pos;
		}
		void Clear()
		{
			PNode cur = _head->_next;
			while (cur != _head){
				PNode next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		//////////////////////////////////////////////////////////////
		//List Capacity
		size_t Size() const
		{
			size_t count = 0;
			PNode cur = _head->_next;
			while (cur != _head){
				++count;
				cur = cur->_next;
			}
			return count;
		}

		bool Empty() const
		{
			return _head->_next == _head;
		}

		void ReSize(size_t newSize, const T& val = T())
		{
			size_t oldSize = Size();
			if (oldSize <= newSize){
				for (size_t i = oldSize; i < newSize; ++i){
					PushBack(val);
				}
			}
			else{
				for (size_t i = newSize; i < oldSize; ++i){
					PopBack();
				}
			}
		}
	private:
		PNode _head;
	};
}