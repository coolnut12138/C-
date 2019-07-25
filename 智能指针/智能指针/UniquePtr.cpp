#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	int _num;
};

int main()
{
	unique_ptr<A> uq(new A);
	unique_ptr<A> uq2;
	return 0;
}
//
//template <class T>
//class UniquePtr
//{
//public:
//	UniquePtr()
//		:_ptr(nullptr)
//	{}
//	~UniquePtr()
//	{
//		if(_ptr)
//			delete _ptr;
//	}
//	T* operator->()
//	{ return _ptr; }
//
//	T& operator*()
//	{ return *_ptr; }
//private:
//	UniquePtr(const UniquePtr<T>&) = delete;
//	UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	UniquePtr<A> up;
//	up->_num = 1;
//	UniquePtr<A> up2;
//	up2 = up;
//
//	return 0;
//}