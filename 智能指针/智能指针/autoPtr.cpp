//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//	int _num;
//};
//
//template <class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//
//	~AutoPtr()
//	{
//		if (_ptr) {
//			delete _ptr;
//		}
//	}
//
//	//拷贝
//	AutoPtr(AutoPtr& ap)
//	{
//		_ptr = ap._ptr;
//		ap._ptr = nullptr;		//资源转移，管理权移交，ap的管理权失效
//	}
//
//	//赋值
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (this != &ap) {
//			//释放当前对象的资源
//			if (_ptr) {
//				delete _ptr;
//			}
//
//			//将新来的资源移交给自己
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		return *this;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	AutoPtr<A> ap(new A);
//	ap->_num = 2;
//	AutoPtr<A> ap2;
//	ap2 = ap;
//	ap2->_num = 3;
//	ap->_num = 4;
//	return 0;
//}