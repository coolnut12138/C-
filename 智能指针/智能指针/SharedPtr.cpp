//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//
//template <class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//		,_mutex(new mutex)
//		,_Count(new int(1))
//	{}
//	~SharedPtr()
//	{
//		Release();
//	}
//
//	SharedPtr(const SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		, _mutex(sp._mutex)
//		, _Count(sp._Count)
//	{
//		AddRefCount();
//	}
//
//	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
//	{
//		if (_ptr != sp._ptr) {
//			Release();
//
//			_ptr = sp._ptr;
//			_mutex = sp._mutex;
//			_Count = sp._Count;
//
//			AddRefCount();
//		}
//		return *this;
//	}
//
//	T* operator->()
//	{ return _ptr; }
//
//	T& operator*()
//	{ return *_ptr; }
//
//	int UseCount()
//	{
//		return *_Count;
//	}
//
//	void AddRefCount()
//	{
//		_mutex->lock();
//		++(*_Count);
//		_mutex->unlock();
//	}
//private:
//	void Release()
//	{
//		bool flag = false;	//计数为0标志位
//		_mutex->lock();
//		if (--(*_Count) == 0) {
//			delete _ptr;
//			delete _Count;
//			flag = true;
//		}
//		_mutex->unlock();
//
//		if (flag == true)
//			delete _mutex;
//	}
//private:
//	T* _ptr;	//指向管理资源的指针
//	mutex* _mutex;	//互斥锁
//	int* _Count;	//引用计数
//};
//
//int main()
//{
//	SharedPtr<int> sp1(new int(10));
//	SharedPtr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	SharedPtr<int> sp3(new int(10));
//	sp2 = sp3;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//	sp1 = sp3;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//	return 0;
//}



#include <iostream>
#include <memory>
using namespace std;
//
//struct ListNode
//{
//	int data;
//	weak_ptr<ListNode> _next;
//	weak_ptr<ListNode> _prev;
//	~ListNode() { cout << "~ListNode()" << endl; }
//};
//
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}

