#define _CRT_SECURE_NO_WARNINGS
#if 0
//���룺abc##de#g##f###
//�����c b e g d f a
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
	//Ĭ�Ͽ�������û����ʽʵ�֣����Ի����ϵͳ���ɵ�Ĭ�Ͽ������캯��������ǳ������Ҳ����str1��str2ָ��ͬһ���ڴ�ռ�
	//��ô���������ʱ�����ͷŵ�str2ָ��Ŀռ䣬��ʱstr1��ΪҰָ�룬���ͷ�str1�ͻ�����⣬�������������Ҫʹ�����
	String str2(str1);
}

int main()
{
	TestString();
	return 0;
}
#endif

#if 0
//��ͳ��String��
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