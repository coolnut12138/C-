#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//�����������ò��ã���Ҫ��ǰ׼���ã�
//1�����캯��˽��
//2������һ��������̬��Ա����̬��Ա�ڳ�������֮ǰ��ɳ�ʼ��
//3���ṩһ����̬������ȡ������̬��Ա
//4��������
class Singleton
{
public:
	//�������ú�ָ�룬��֤ȫ��Ψһ
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//���캯��˽��
	Singleton()
	{}
	//��ֹ���������ַ��������ԣ�1��������˽�У����Բ�ʵ��
	//						  2��������һ��delete����
	Singleton(Singleton const&);
	//Singleton(const Singleton& s) = delete;
	Singleton& operator=(Singleton const&);
	static Singleton m_instance;
};

Singleton Singleton::m_instance;	//��̬��Ա�����������ʼ��