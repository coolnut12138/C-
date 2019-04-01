#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
//����
//1�����캯��˽��
//2��������������
//3���ṩ��̬�̰߳�ȫ�Ľӿڣ�double check�����Ч�ʣ�
//4������һ����̬�������͵�ָ�룬��ʼ��Ϊnullptr
//5��(��ѡ)����һ���ڲ��࣬�����ͷŵ���ָ��
class Singleton
{
public:
	static Singleton* getInstance()
	{
		//���߳�ʱ��ߺ����̵߳��ýӿڵ�Ч��
		if (m_pInstance == nullptr)
		{
			m_mtx.lock();
			//��֤����ֻ����һ�Σ���ֹ�ڴ�й©
			if (m_pInstance == nullptr)
			{
				m_pInstance = new Singleton;
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
private:
	//���캯��˽��
	Singleton(){};
	//��������˽��
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance;	//��������ָ��
	static mutex m_mtx;				//������
};

Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_mtx;
