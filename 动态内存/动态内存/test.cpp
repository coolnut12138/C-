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
	//new ���������ռ������
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
	//��֤ malloc/new �� delete/free ��ƥ��ʹ�û���ֵ����
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
	//delete pt1;	//���mallocһ��Test���͵Ķ��������delete�ͷŻ���ɴ������
	//�����Զ������ͣ�malloc������ǺͶ�����ͬ��С�Ķ��ϵĿռ䣬���ܿ��ɶ����ͷ�Ҳ���൱�ͷ�һ�οռ�

	Test* pt2 = new Test;
	free(pt2);
	//delete pt2;
	//new ������Զ������͵Ĺ��캯����delete ������Զ������͵���������
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
	
	//���ڴ������ռ䣬����û�е��ù��캯��
	pt = (Test*)Allocate(sizeof(Test));
	//�����ö�λnew���ʽ(placement new)�����Ѿ����ڵĿռ���ִ�й��캯��
	new(pt) Test;	//new(��ַ) ���͹��캯��
	
	return 0;
}
#endif


#if 0
//ֻ���ڶ��ϴ�������
//ջ�ϡ�ȫ�������򡢾�̬�������ܴ�����ֻ���ڶ��ϴ���
class HeapObj
{
public:
	//�ṩһ�����еķ��������ʹ��캯��
	//����static�Ϳ��������ⲻ�������������������Ա������
	static HeapObj* CreateInstrance(int param)
	{
		return new HeapObj(param);
	}
private:
	HeapObj(int)
	{}

	HeapObj(const HeapObj&);	//������ڹ��еģ���ô�п��ܻ������ⶨ�壬���ǻ���ÿ�������
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
//���һ���࣬��ֹ������
//class Test
//{
//public:
//	Test()
//	{}
//private:
//	Test(const Test& t);
//	Test& operator=(const Test& t);
//};

//����
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