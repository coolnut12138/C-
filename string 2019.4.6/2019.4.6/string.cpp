#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//深拷贝：传统方式
class String
{
public:
	String(char* str = "")
	{	
		/*if (nullptr == str)
		{
			_str = new char[1];
			*_str = '\0';
		}
		else{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}*/
		if (nullptr == str){
			str = "";
		}
		_str = new char[strlen(str) + 1];
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
			//delete[] _str;
			//_str = new char[strlen(s._str) + 1];	//这种方法的缺点：因为是先释放原有空间，再开辟新的空间，
													//如果开辟新空间失败了，那么原有数据也找不到了
			//strcpy(_str, s._str);

			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

//深拷贝：现代版---简洁版
//class String
//{
//public:
//	String(char* str = "")
//	{
//		if (nullptr == str){
//				str = "";
//			}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		:_str(nullptr)			//如果没有初始化列表，在低版本的编译器中拷贝构造的对象指针是随机值(就是此
//								处的s是随机值),当swap交换完，函数结束，空间释放随机值的指针程序就会崩溃
//	{
//		String strTemp(s._str);
//		swap(_str, strTemp._str);
//	}
//
//	/*String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			String strTemp(s);
//			swap(_str, strTemp._str);
//		}
//		return *this;
//	}*/
//
//	/*String& operator=(const String& s)
//	{
//		String strTemp(s);
//		swap(_str, strTemp._str);
//		
//		return *this;
//	}*/
//
//	String& operator=(String s)
//	{
//		swap(_str, s._str);		//此时s是值传递，会创建一个临时对象，所以不会出现自己给自己赋值的情况
//								swap改变指针的指向，出了函数作用域，销毁的就是原来this指向的空间。
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};