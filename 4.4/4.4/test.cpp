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
//	////�������ͣ��������ͣ�
//	//int *p1 = new int;
//	//int *p2 = (int*)malloc(sizeof(int));
//
//	//delete p1;
//	//free(p2);
//
//	////�Զ�������
//	//Date* p3 = new Date;	//���ռ�+��ʼ��
//	//Date* p5 = new Date(2019, 4, 4);
//	//Date* p4 = (Date*)malloc(sizeof(Date));	//���ռ�
//	//
//	//delete p3;
//	//delete p5;	//������������+ �ͷſռ�
//	//free(p4);	//�ͷſռ�
//
//	//Date* p6 = new Date[10];	//������ʮ�ι���
//	//delete[] p6;	//����ʮ������
//
//	/*int *p1 = (int*)operator new(sizeof(int));
//	operator delete(p1);*/
//	try
//	{
//		char* p1 = (char*)operator new(0x7fffffff);	//ʧ�� ���쳣
//
//		char* p2 = (char*)malloc(0xffffffff);	//ʧ�� ����0
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
//	l.PushBack(1);		//����һ����ר����operator new/operator delete
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//	l.PushBack(5);
//
//	Date p;
//	return 0;
//}

//ֻ���ڶ��ϴ�������
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()	//���������Ϊ��̬�ģ���ô�������������Ҫʹ�ö���������
									//��������ǹ��캯����֮ǰ��û�ж���ģ�
									//���Զ���Ϊ��̬�����Ϳ�����HeapOnly::GetHeapObj()�����á�
	{
		return new HeapOnly;
	}

	//�������������ֲ�����ջ�ϵ��õķ���
	//1����������������Ϊ˽��		C++98	
	//����������һ��ȱ��->����ʹ����Ԫ����������ʹ����Ԫ����������˽�еĿ���������Ȼ���Ե��á�
	//�������ʹ�� C++11 �� delete
	//2��delete����		C++11
	HeapOnly(const HeapOnly&) = delete;
private:
	HeapOnly()	//1.���ֻ�����캯����Ϊ˽�еģ���ô��Ȼ������ջ�ϴ�������
				//�ڶ���Ҳ���ܵ��ù��캯�����������ˡ�����Ӧ���ṩһ�����еĳ�Ա������������
	{}

	//HeapOnly(const HeapOnly&);	//����������ֻ������ʵ�֣���ô�͵������ˡ�
};

//int main()
//{
//	//HeapOnly obj1;	//��ջ���޷���������
//	HeapOnly* pobj = HeapOnly::GetHeapObj();	//�ڶ��ϴ�������
//	//HeapOnly p(pobj);	//�޷����ÿ�������
//	return 0;
//}

//���һ����ֻ����ջ�ϴ�������
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();
//	}
//	//�������������ֻ����ջ�����Բ��ý��������졣
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
//	void operator delete(void* p);		//���ַ���ֻ�ܽ������ϵĶ��󣬵���ȫ�ֶ�����Ȼ�����ɡ������ᳫʹ�÷���һ
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
//	Singleton()	//���캯��˽��
//	{
//		//��ʼ��
//	}
//	//c++98������
//	Singleton(const Singleton&);
//	Singleton& operator=(Singleton const&);
//
//	//c++11������
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton _sinst;
//};
//Singleton Singleton::_sinst;


//����
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
	//����˽��
	Singleton()
	{};
	//������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance;	//��������ָ��
	static mutex m_mtx;			//������
};

Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_mtx;

////��ͨģʽ��
//m_mtx.lock();
//if (nullptr == m_pInstance) 
//{
//	//����������̣߳�����һ���߳��ߵ��⣬�ڶ����̻߳ᱻ�����������𵽵��������ã�
//	//�����ж���߳�ʱ������һ���߳��Ѿ�new������ʱ����ô������߳̾�û��Ҫ�������Ŷӵ��ż���ˣ�������˷�
//	m_pInstance = new Singleton();
//}
//m_mtx.unlock();
//
////�����������ô���߳�ʱ������һ�����̽���lock�󴴽����󣬱���̻߳���lock���ȴ���
//if (nullptr == m_pInstance)
//{
//	m_mtx.lock();
//	//���ڴ˴�û�еڶ�����飬���Ե���һ���߳̽����󣬵ڶ����߳̾�ֱ��new�����󣬵��²��ǵ�������
//	m_pInstance = new Singleton();
//	
//	m_mtx.unlock();
//}
//
////�����ж���߳�ʱ��double check
//if (nullptr == m_pInstance)		//����������Ѿ��ж��󴴽�����֮�󣬵�����߳��ߵ���ʱ���м�飬
//								//����Ѿ��ж�����ôֱ�ӷ��أ��Ͳ�����ȥ�������Ĳ��裬�����Ч��
//{
//	m_mtx.lock();
//	if (nullptr == m_pInstance)		//������ǵ�һ���߳�Ҫnew֮ǰ���ж��Ƿ��Ѿ�����������
//	{
//		m_pInstance = new Singleton();
//	}
//	m_mtx.unlock();
//}