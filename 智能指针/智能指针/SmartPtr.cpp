#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>

#if 0
template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		cout << "~SmartPtr()" << endl;
		if (_ptr){
			delete[] _ptr;
		}
	}
private:
	T* _ptr;
};

void _MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right){
		return;
	}

	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left;
	int begin2 = mid + 1;
	int index = left;
	while (begin1 <= mid && begin2 <= right){
		if (a[begin1] < a[begin2]){
			tmp[index++] = a[begin1];
		}
		else{
			tmp[index++] = a[begin2];
		}
	}
	while (begin1 <= mid){
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= right){
		tmp[index++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
void MergeSort(int *a, int n)
{
	//int *tmp = new int[n];
	SmartPtr<int> sp(new int[n]);
	//_MergeSort(a, 0, n - 1, tmp);

	vector<int> v(1000000000, 10);
}
int main()
{
	try{
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);
	}
	catch (const exception& e){
		cout << e.what() << endl;
	}

	cout << "finish~~" << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//简单的智能指针实现
//1、首先利用对象的生命周期管理资源
//2、实现指针的功能（解引用、++）
template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr){
			delete _ptr;
		}
		cout << "~SmartPtr()" << endl;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

struct Date
{
	int _year;
	int _month;
	int _day;
};

int main()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;
	
	SmartPtr<Date> sparray(new Date);
	sparray->_year = 2019;
	sparray->_month = 1;
	sparray->_day = 1;
	return 0;
}

#endif

#if 0
//auto_ptr的使用
#include <memory>

class Date
{
public:
	Date(){ cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }
	
	int _year;
	int _month;
	int _day;
};

int main()
{
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	
	//此时ap指针已经失效
	//auto_ptr的问题：当对象拷贝或赋值后，前面的对象就悬空了
	ap->_year = 1990;

	return 0;
}
#endif

#if 0
//模拟实现auto_ptr
template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr){
			delete _ptr;
		}
		cout << "~SmartPtr()" << endl;
	}

	//管理权转移
	SmartPtr(SmartPtr<T>& sp)
		:_ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}
	SmartPtr& operator=(SmartPtr<T>& sp)
	{
		if (this != &sp)
		{
			if (_ptr){
				delete _ptr;
			}
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

class Date
{
public:
	Date(){ cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};

int main()
{
	SmartPtr<Date> ap(new Date);
	SmartPtr<Date> copy(ap);

	//此时ap指针已经失效
	//auto_ptr的问题：当对象拷贝或赋值后，前面的对象就悬空了
	ap->_year = 1990;

	return 0;
}
#endif

class Date
{
public:
	Date(){ cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};

#if 0
//模拟实现unique_ptr
template <class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr){
			delete _ptr;
		}
	}

	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}

	//防拷贝
	UniquePtr(UniquePtr<T> const& sp) = delete;
	UniquePtr& operator=(UniquePtr<T> const& sp) = delete;
private:
	T* _ptr;
};

int main()
{
	UniquePtr<Date> up(new Date);
	//防拷贝
	//UniquePtr<Date> up2(up);
	UniquePtr<Date> up3(new Date);
	//防拷贝
	//up3 = up;
}
#endif

#if 0
//模拟实现简单的SharedPtr
#include <mutex>
#include <thread>

template <class T>
class SharedPtr
{

};
#endif
