#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace myVector{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		typedef const T* const_Iterator;

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorge(nullptr)
		{}

		Vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorge(nullptr)
		{
			Reserve(n);
			while (n--){
				PushBack(value);
			}
		}

		//这里如果使用Iterator做迭代器，就会导致初始化的迭代器区间[first，last]只能是Vector的迭代器
		//这里重新声明迭代器，迭代器区间[first, last]可以是任意容器的迭代器区间
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		Vector(const Vector<T>& v)
		{
			//深拷贝--->开空间--->拷贝
			_start = new T[v.Capacity()];
			for (size_t i = 0; i < v.Size(); i++)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.Size();
			_endOfStorge = _start + v.Capacity();
		}

		void PushBack(const T& val)
		{
			//考虑扩容
			if (_finish == _endOfStorge)
			{
				size_t newCapacity = (_start == nullptr ? 1 : 2 * Capacity());
				Reserve(newCapacity);
			}
			*_finish++ = val;
		}

		Vector<T> operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		void Swap(Vector<T>& v)
		{
			//现代版
			//v是局部对象，出了作用域会释放，交换指针指向的做法
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorge, v._endOfStorge);
		}

		void PopBack()
		{
			Erase(end() - 1);
		}

		Iterator begin()
		{
			return _start;
		}

		Iterator end()
		{
			return _finish;
		}

		const_Iterator begin() const
		{
			return _start;
		}

		const_Iterator end() const
		{
			return _finish;
		}

		void Reserve(size_t capacity)
		{
			if (capacity > Capacity())
			{
				//三大步：1、开空间 2、深拷贝 3、更新指针
				int len = Size();
				T* newC = new T[capacity];
				if (_start)
				{
					for (int i = 0; i < len; i++)
					{
						newC[i] = _start[i];
					}
					delete[] _start;
				}
				_start = newC;
				_finish = _start + len;
				_endOfStorge = _start + capacity;
			}
		}

		void Resize(size_t n, const T& val = T())
		{
			//n 小于当前的 size，将数据个数缩小到 n
			if (n <= Size())
			{
				_finish = _start + n;
			}
			else{
				//n > 当前的容量，容量不够则增容
				if (n > Capacity())
				{
					Reserve(n);
				}
				//新增位置赋值
				while (_finish != _start + n){
					*_finish = val;
					++_finish;
				}
			}
		}

		void Insert(Iterator pos, const T& val)
		{
			assert(pos < _finish && pos >= _start);
			int len = pos - _start;

			//容量不够则扩容
			if (_finish == _endOfStorge)
			{
				size_t newC = _start == nullptr ? 1 : 2 * Capacity();
				Reserve(newC);
			}
			
			//增容之后更新迭代器
			pos = _start + len;
			Iterator end = _finish;

			//从后向前挪动元素，腾出pos的空间，放入新元素
			while (end != pos){
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			_finish++;
		}

		Iterator Erase(Iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			//删除pos的位置，让pos+1的位置向前依次挪动
			Iterator begin = pos + 1;
			while (begin != _finish){
				*(begin - 1) = *begin;
				begin++;
			}

			--_finish;
			return pos;
		}

		size_t Size() const
		{
			return _finish - _start;
		}

		size_t Capacity() const
		{
			return _endOfStorge - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < Size());
			return _start[pos];
		}

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorge = nullptr;
			}
		}
	private:
		T* _start;				//指向数据块的开始
		T* _finish;				//指向数据块的尾
		T* _endOfStorge;		//指向存储容量的尾
	};
}

template<class T>
void PrintVector(const myVector::Vector<T>& v)
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

template<class T>
void PrintVectorWithIterator(const myVector::Vector<T>& v)
{
	auto vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

template<class T>
void PrintVectorWithFor(const myVector::Vector<T>& v)
{
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector1()
{
	myVector::Vector<int> first;	//空vector
	myVector::Vector<int> second(4, 100);	//4个int型空间，值为100
	myVector::Vector<int> third(second.begin(), second.end());	
	myVector::Vector<int> forth(third);

	int ints[] = { 2, 3, 1, 47 };
	myVector::Vector<int> fifth(ints, ints + sizeof(ints) / sizeof(ints[0]));

	PrintVectorWithIterator(first);
	PrintVectorWithIterator(second);
	PrintVectorWithIterator(third);
	PrintVectorWithIterator(forth);
	PrintVectorWithIterator(fifth);

	//测试string类型
	myVector::Vector<string> strV;
	strV.PushBack("abc");
	strV.PushBack("def");
	strV.PushBack("ghj");
	strV.PopBack();
	PrintVectorWithFor(strV);
}

void TestVector2()
{
	//使用PushBack插入4个数据
	myVector::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	//使用迭代器打印
	myVector::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//使用迭代器修改
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	PrintVectorWithIterator(v);
}

void TestVector3()
{
	size_t sz;
	myVector::Vector<int> foo;
	sz = foo.Capacity();
	cout << "making foo growing:" << endl;
	for (int i = 0; i < 100; i++)
	{
		foo.PushBack(i);
		if (sz != foo.Capacity())
		{
			sz = foo.Capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	//reserve
	myVector::Vector<int> bar;
	sz = bar.Capacity();
	bar.Reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		bar.PushBack(i);
		if (sz != bar.Capacity()) {
			sz = bar.Capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	// resize
	myVector::Vector<int> myvector;
	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.PushBack(i);
	myvector.Resize(5);
	myvector.Resize(8, 100);
	myvector.Resize(12);
	std::cout << "myvector contains:";
	for(size_t i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

// find / insert / erase
void TestVector4()
{
	int a[] = { 1, 2, 3, 4 };
	myVector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	myVector::Vector<int>::Iterator pos = find(v.begin(), v.end(), 3);
	// 在pos位置之前插入30
	v.Insert(pos, 30);
	myVector::Vector<int>::Iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据
	v.Erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// iterator失效问题
void TestVector5()
{
	int a[] = { 1, 2, 3, 4 };
	myVector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	myVector::Vector<int>::Iterator pos = find(v.begin(), v.end(), 3);
	//// 删除pos位置的数据，导致pos迭代器失效。
	//v.Erase(pos);
	//cout << *pos << endl; // 此处会导致非法访问
	
	//// 在pos位置插入数据，导致pos迭代器失效。
	//// insert会导致迭代器失效，是因为insert可
	//// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	//pos = find(v.begin(), v.end(), 3);
	//v.Insert(pos, 30);
	//cout << *pos << endl; // 此处会导致非法访问
	
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	myVector::Vector<int>::Iterator it = v.begin();
	/*while (it != v.end())
	{
		if (*it % 2 == 0)
			v.Erase(it);
		++it;
	}*/
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		it = v.Erase(it);
		else
			++it;
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	TestVector5();
	system("pause");
	return 0;
}