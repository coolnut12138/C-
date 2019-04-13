#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
class Vector
{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorge(nullptr)
	{}

	Vector(const Vector<T>& v)
	{
		//考虑深拷贝、开空间、拷贝
		_start = new T[v.Capacity()];
		for (size_t i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endOfStorge = _start + v.Capacity();
	}

	//Vector<T>& operator=(const Vector<T>& v)
	//{
	//	//1、检查是否自己赋值
	//	//2、返回值类型：引用，为了连续赋值
	//	//3、返回：*this
	//	if (*this != &v)
	//	{
	//		T* tmp = new T[v.Capacity()];
	//		for (size_t i = 0; i < v.Size(); i++)
	//		{
	//			tmp[i] = v[i];
	//		}
	//		if (_start)
	//		{
	//			delete[] _start;
	//		}
	//		_start = tmp;
	//		_finish = _start + v.Size();
	//		_endOfStorge = _start + v.Capacity();
	//	}
	//	return *this;
	//}

	Vector<T> operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorge, v._endOfStorge);
	}

	void PushBack(const T& val)
	{
		//判断容量
		if (_finish == _endOfStorge)
		{
			//扩容
			size_t newCapacity = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newCapacity);
		}
		*_finish++ = val;
	}

	void Reserve(size_t capacity)
	{
		if (capacity > Capacity())
		{
			int len = Size();
			//1、开辟新的空间
			T* tmp = new T[capacity];
			//拷贝原有空间的内容
			//memcpy是浅拷贝，最终会导致空间释放两次，所以用深拷贝
			/*if (_start)
			{
				memcpy(tmp, _start, sizeof(T) * len);
				delete[] _start;
			}*/
			//2、调用自定义类型的赋值运算符重载，进行深拷贝
			if (_start)
			{
				for (int i = 0; i < len; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			//3、更新指针
			_start = tmp;
			_finish = _start + len;
			_endOfStorge = _start + capacity;
		}
	}

	size_t Size()
	{
		return _finish - _start;
	}

	size_t Capacity()
	{
		return _endOfStorge - _start;
	}

	//可读可写的[]
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	//只读的[]
	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	bool Empty()
	{
		return _start == _finish;
	}
private:
	T* _start;
	T* _finish;
	T* _endOfStorge;
};

template<class T>
void PrintVectorFor(const Vector<T>& v)
{
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	/*v.PushBack("a");
	v.PushBack("b");
	v.PushBack("c");*/

	Vector<int> v2(v);

	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	for (size_t i = 0; i < v2.Size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}

int main()
{
	Test1();
	system("pause");
	return 0;
}