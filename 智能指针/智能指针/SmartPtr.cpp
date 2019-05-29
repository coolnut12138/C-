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

	int _year = 1990;
	int _month = 1;
	int _day = 1;
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
#include <memory>
//使用shared_ptr
int main()
{
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);
	sp->_year = 10;
	cout << sp.use_count() << endl;
	cout << copy.use_count() << endl;	//连接同一份资源，两个指针的计数都加1
	return 0;
}
#endif

#if 1
//模拟实现简单的SharedPtr
#include <mutex>
#include <thread>

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pMutex(new mutex)
		, _pRefCount(new int(1))
	{}

	~SharedPtr()
	{
		if (subCount() == 0){
			if (_ptr){
				delete _ptr;
				delete _pRefCount;
				delete _pMutex;
				_pMutex = nullptr;
				_pRefCount = nullptr;
				_ptr = nullptr;
			}
		}
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr){
			//与原有资源断开连接
			if (--(*_pRefCount) == 0){
				delete _ptr;
				delete _pRefCount;
				delete _pMutex;
				_pMutex = nullptr;
				_pRefCount = nullptr;
				_ptr = nullptr;
			}

			//建立新的连接
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			//计数加一
			AddRefCount();
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

	int UseCount()
	{
		return *_pRefCount;
	}

	int subCount()
	{
		_pMutex->lock();
		--(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}

	int AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
private:
	T* _ptr;	//管理资源的指针
	int* _pRefCount;	//引用计数
	mutex* _pMutex;	//互斥锁
};
mutex mtx;
void funC(SharedPtr<Date>& sp, int num)
{
	for (int i = 0; i < num; i++)
	{
		SharedPtr<Date> spcopy(sp);
		mtx.lock();
		sp->_year++;
		mtx.unlock();
	}

}

int main()
{
	SharedPtr<Date> sp(new Date);
	SharedPtr<Date> sp2(new Date);
	int num;
	cin >> num;
	thread t1(funC, sp, num);
	thread t2(funC, sp, num);
	t1.join();
	t2.join();
	cout << "year: " << sp->_year << endl;
	//cout << sp.UseCount() << endl;
	//cout << copy.UseCount() << endl;
	system("pause");
	return 0;
}
#endif


