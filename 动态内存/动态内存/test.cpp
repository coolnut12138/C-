#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
int main()
{
	int *pt = (int*)malloc(sizeof(int)* 10);
	free(pt);	//free(nullptr);

	return 0;
}
#endif

#if 0
int main()
{
	//new 后跟所申请空间的类型
	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[10];

	delete p1;
	delete p2;
	delete[] p3;
	return 0;
}
#endif

#include <crtdbg.h>

#if 0
void TestFunc()
{
	//验证 malloc/new 和 delete/free 不匹配使用会出现的情况
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));

	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;

	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	/*free(p5);
	free(p6);*/

	_CrtDumpMemoryLeaks();
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
		_t = 0;
		_ptr = (int*)malloc(sizeof(int));
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
		if (nullptr != _ptr)
		{
			free(_ptr);
			_ptr = nullptr;
		}
	}
private:
	int _t;
	int* _ptr;
};

int main()
{
	Test* pt1 = (Test*)malloc(sizeof(Test));
	free(pt1);
	//delete pt1;	//如果malloc一个Test类型的对象，如果用delete释放会造成代码崩溃
	//对于自定义类型，malloc申请的是和对象相同大小的堆上的空间，不能看成对象，释放也就相当释放一段空间

	Test* pt2 = new Test;
	free(pt2);
	//delete pt2;
	//new 会调用自定义类型的构造函数，delete 会调用自定义类型的析构函数
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

void* operator new(size_t size, char* fileName, char* funcName, int lineNo)
{
	cout << fileName << ":" << funcName << ":" << lineNo << ":" << size << endl;
	return malloc(size);
}

#ifdef _DEBUG
#define new new(__FILE__, __FUNCTION__, __LINE__)
#endif

#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};

void* Allocate(size_t size)
{
	return malloc(size);
}

int main()
{
	//Test* pt = new(__FILE__, __FUNCTION__, __LINE__) Test;
	Test* pt = new Test;
	delete pt;
	
	//从内存池申请空间，但是没有调用构造函数
	pt = (Test*)Allocate(sizeof(Test));
	//所以用定位new表达式(placement new)，在已经存在的空间上执行构造函数
	new(pt) Test;	//new(地址) 类型构造函数
	
	return 0;
}
#endif


#if 0
//只能在堆上创建对象
//栈上、全局作用域、静态区都不能创建，只能在堆上创建
class HeapObj
{
public:
	//提供一个公有的方法来访问构造函数
	//给成static就可以在类外不依赖对象来调用这个成员函数。
	static HeapObj* CreateInstrance(int param)
	{
		return new HeapObj(param);
	}
private:
	HeapObj(int)
	{}

	HeapObj(const HeapObj&);	//如果放在公有的，那么有可能会在类外定义，还是会调用拷贝构造
};

int main()
{
	HeapObj* p = HeapObj::CreateInstrance(10);
	return 0;
}
#endif

#if 0
class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
};

int main()
{
	StackOnly t;
	return 0;
}
#endif

#if 0
//设计一个类，防止被拷贝
//class Test
//{
//public:
//	Test()
//	{}
//private:
//	Test(const Test& t);
//	Test& operator=(const Test& t);
//};

//或者
class Test
{
public:
	Test()
	{}
	Test(const Test& t) = delete;
	Test& operator=(const Test& t);
};
#endif

int add(int a, int b, int c)
{
	return a + b + c;
}
#include <string.h>
int main()
{
	/*void *p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;*/
	/*int a = 1, b = 2, c = 3;
	add(a, b, c);

	int* x = (int*)malloc(sizeof(int));
	int* y = (int*)malloc(sizeof(int));
	int* z = (int*)malloc(sizeof(int));*/

	char arr[] = "abcdef";
	cout << sizeof(arr) << endl;
	cout << strlen(arr) << endl;
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << sizeof(arr2) << endl;
	//cout << strlen(arr2) << endl;
	return 0;
}