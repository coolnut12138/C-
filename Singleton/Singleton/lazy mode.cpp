#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
//懒汉
//1、构造函数私有
//2、封死拷贝构造
//3、提供静态线程安全的接口（double check，提高效率）
//4、定义一个静态单例类型的指针，初始化为nullptr
//5、(可选)定义一个内部类，辅助释放单例指针
class Singleton
{
public:
	static Singleton* getInstance()
	{
		//多线程时提高后续线程调用接口的效率
		if (m_pInstance == nullptr)
		{
			m_mtx.lock();
			//保证对象只创建一次，防止内存泄漏
			if (m_pInstance == nullptr)
			{
				m_pInstance = new Singleton;
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
private:
	//构造函数私有
	Singleton(){};
	//拷贝构造私有
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance;	//单例对象指针
	static mutex m_mtx;				//互斥锁
};

Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_mtx;
