#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "year = 1900, month = 1, day = 1" << endl;
	}

	~Date()
	{
		cout << "~Date" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//
//int main()
//{
//	////基本类型（内置类型）
//	//int *p1 = new int;
//	//int *p2 = (int*)malloc(sizeof(int));
//
//	//delete p1;
//	//free(p2);
//
//	////自定义类型
//	//Date* p3 = new Date;	//开空间+初始化
//	//Date* p5 = new Date(2019, 4, 4);
//	//Date* p4 = (Date*)malloc(sizeof(Date));	//开空间
//	//
//	//delete p3;
//	//delete p5;	//先析构（清理）+ 释放空间
//	//free(p4);	//释放空间
//
//	//Date* p6 = new Date[10];	//这会调用十次构造
//	//delete[] p6;	//调用十次析构
//
//	/*int *p1 = (int*)operator new(sizeof(int));
//	operator delete(p1);*/
//	try
//	{
//		char* p1 = (char*)operator new(0x7fffffff);	//失败 抛异常
//
//		char* p2 = (char*)malloc(0xffffffff);	//失败 返回0
//		cout << p2 << endl;
//	}
//	catch (exception e)
//	{
//		cout << e.what() << endl;
//	}
//	
//	system("pause");
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//
//	ListNode(int data = 0)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _data(data)
//	{}
//
//	void* operator new(size_t size)
//	{
//		void* p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate ListNode" << endl;
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_prev = _head;
//		_head->_next = _head;
//	}
//
//	void PushBack(int x)
//	{
//		ListNode* tail = _head->_prev;
//		ListNode* newnode = new ListNode;
//		//tail  newnode  _head
//		tail->_next = newnode;
//		newnode->_next = _head;
//		_head->_prev = newnode;
//		newnode->_prev = tail;
//	}
//
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head){
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List l;
//	l.PushBack(1);		//定义一个类专属的operator new/operator delete
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//	l.PushBack(5);
//
//	Date p;
//	return 0;
//}

//只能在堆上创建对象
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()	//如果不定义为静态的，那么调用这个函数就要使用对象来调，
									//可是这就是构造函数，之前是没有对象的，
									//所以定义为静态函数就可以用HeapOnly::GetHeapObj()来调用。
	{
		return new HeapOnly;
	}

	//拷贝构造有两种不能在栈上调用的方法
	//1、将拷贝函数声明为私有		C++98	
	//但是这种有一种缺陷->可以使用友元函数来调，使用友元函数来调用私有的拷贝构造依然可以调用。
	//所以最好使用 C++11 的 delete
	//2、delete函数		C++11
	HeapOnly(const HeapOnly&) = delete;
private:
	HeapOnly()	//1.如果只将构造函数设为私有的，那么虽然不能在栈上创建对象，
				//在堆上也不能调用构造函数创建对象了。所以应该提供一个公有的成员函数来调构造
	{}

	//HeapOnly(const HeapOnly&);	//将拷贝函数只声明不实现，那么就调不动了。
};

//int main()
//{
//	//HeapOnly obj1;	//在栈上无法创建对象
//	HeapOnly* pobj = HeapOnly::GetHeapObj();	//在堆上创建对象
//	//HeapOnly p(pobj);	//无法调用拷贝构造
//	return 0;
//}

//设计一个类只能在栈上创建对象
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();
//	}
//	//拷贝构造出来的只能在栈上所以不用禁拷贝构造。
//private:
//	StackOnly()
//	{}
//}; 

//class StackOnly
//{
//public:
//	StackOnly()
//	{}
//private:
//	void* operator new(size_t size);
//	void operator delete(void* p);		//这种方法只能禁掉堆上的对象，但是全局对象依然能生成。所以提倡使用方法一
//	//void* operator new(size_t size) = delete;
//	//void operator delete(void* p) = delete;
//};
//
//int main()
//{
//	//StackOnly p = new StackOnly;
//	//StackOnly stobj = StackOnly::GetStackObj();
//	StackOnly stobj = new StackOnly;
//	return 0;
//}

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &_sinst;
//	}
//private:
//	Singleton()	//构造函数私有
//	{
//		//初始化
//	}
//	//c++98防拷贝
//	Singleton(const Singleton&);
//	Singleton& operator=(Singleton const&);
//
//	//c++11防拷贝
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton _sinst;
//};
//Singleton Singleton::_sinst;


//懒汉
#include <thread>
#include <mutex>
class Singleton
{
public:
	static Singleton* GetInstance(){
		if (m_pInstance == nullptr){
			m_mtx.lock();
			if (m_pInstance == nullptr){
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
	}
private:
	//构造私有
	Singleton()
	{};
	//防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance;	//单例对象指针
	static mutex m_mtx;			//互斥锁
};

Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_mtx;

////普通模式：
//m_mtx.lock();
//if (nullptr == m_pInstance) 
//{
//	//如果有两个线程，当第一个线程走到这，第二个线程会被锁在锁外面起到单例的作用，
//	//但是有多个线程时，当第一个线程已经new出对象时，那么后面的线程就没必要继续再排队等着检查了，会造成浪费
//	m_pInstance = new Singleton();
//}
//m_mtx.unlock();
//
////如果这样，那么多线程时，当第一个进程进入lock后创建对象，别的线程会在lock处等待，
//if (nullptr == m_pInstance)
//{
//	m_mtx.lock();
//	//由于此处没有第二道检查，所以当第一个线程解锁后，第二个线程就直接new出对象，导致不是单例对象。
//	m_pInstance = new Singleton();
//	
//	m_mtx.unlock();
//}
//
////所以有多个线程时，double check
//if (nullptr == m_pInstance)		//这层检查是在已经有对象创建出来之后，当别的线程走到这时进行检查，
//								//如果已经有对象，那么直接返回，就不用再去进行锁的步骤，提高了效率
//{
//	m_mtx.lock();
//	if (nullptr == m_pInstance)		//这层检查是第一个线程要new之前，判断是否已经创建出对象。
//	{
//		m_pInstance = new Singleton();
//	}
//	m_mtx.unlock();
//}