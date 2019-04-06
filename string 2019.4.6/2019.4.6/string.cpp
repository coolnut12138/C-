#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//�������ͳ��ʽ
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
			//_str = new char[strlen(s._str) + 1];	//���ַ�����ȱ�㣺��Ϊ�����ͷ�ԭ�пռ䣬�ٿ����µĿռ䣬
													//��������¿ռ�ʧ���ˣ���ôԭ������Ҳ�Ҳ�����
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

//������ִ���---����
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
//		:_str(nullptr)			//���û�г�ʼ���б��ڵͰ汾�ı������п�������Ķ���ָ�������ֵ(���Ǵ�
//								����s�����ֵ),��swap�����꣬�����������ռ��ͷ����ֵ��ָ�����ͻ����
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
//		swap(_str, s._str);		//��ʱs��ֵ���ݣ��ᴴ��һ����ʱ�������Բ�������Լ����Լ���ֵ�����
//								swap�ı�ָ���ָ�򣬳��˺������������ٵľ���ԭ��thisָ��Ŀռ䡣
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