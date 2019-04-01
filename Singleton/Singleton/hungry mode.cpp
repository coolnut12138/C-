#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//饿汉（不管用不用，都要提前准备好）
//1、构造函数私有
//2、定义一个单例静态成员，静态成员在程序运行之前完成初始化
//3、提供一个静态方法获取单例静态成员
//4、防拷贝
class Singleton
{
public:
	//返回引用和指针，保证全局唯一
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//构造函数私有
	Singleton()
	{}
	//防止拷贝，两种方法都可以，1、声明成私有，可以不实现
	//						  2、声明成一个delete函数
	Singleton(Singleton const&);
	//Singleton(const Singleton& s) = delete;
	Singleton& operator=(Singleton const&);
	static Singleton m_instance;
};

Singleton Singleton::m_instance;	//静态成员变量在类外初始化