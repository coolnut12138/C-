#define _CRT_SECURE_NO_WARNINGS
#if 0
//输入：abc##de#g##f###
//输出：c b e g d f a
#include <iostream>
#include <string>
using namespace std;

string pre;
int i;

struct Node
{
	char _val;
	struct Node* _left;
	struct Node* _right;
	Node(char val)
		:_val(val)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

struct Node* CreateTree()
{
	char c = pre[i++];
	if (c == '#') {
		return nullptr;
	}
	Node* root = new Node(c);
	root->_left = CreateTree();
	root->_right = CreateTree();
	return root;
}

void InorderTravelsal(struct Node* root)
{
	if (root == nullptr) {
		return;
	}
	InorderTravelsal(root->_left);
	cout << root->_val << " ";
	InorderTravelsal(root->_right);
}


int main()
{
	cin >> pre;
	i = 0;
	struct Node* root = CreateTree();
	InorderTravelsal(root);
	cout << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	~String()
	{
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String str1;
	//默认拷贝构造没有显式实现，所以会调用系统生成的默认拷贝构造函数，这是浅拷贝，也就是str1和str2指向同一块内存空间
	//那么当程序结束时，先释放掉str2指向的空间，此时str1变为野指针，再释放str1就会出问题，程序崩溃，所以要使用深拷贝
	String str2(str1);
}

int main()
{
	TestString();
	return 0;
}
#endif

#if 0
//传统版String类
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr) {
			assert(false);
			return;
		}
		_str = new(char[strlen(str) + 1]);
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char *pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
	}

	~String()
	{
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void testString()
{
	String s1;
	String s2(s1);
}

int main()
{
	testString();
	return 0;
}
#endif

//#include <iostream>
//#include <string.h>
//using namespace std;
//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str) {
//			str = "";
//		}
//		_str = new(char[strlen(str) + 1]);
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String strTmp(s._str);
//		swap(strTmp);
//	}
//private:
//	char* _str;
//};