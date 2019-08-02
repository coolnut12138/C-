#if 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class HungrySingleton
{
public:
	static HungrySingleton* GetInstance()
	{
		return &m_instance;
	}
private:
	HungrySingleton(){}
	HungrySingleton(const HungrySingleton&) = delete;
	HungrySingleton& operator=(const HungrySingleton&) = delete;
	static HungrySingleton m_instance;
};
HungrySingleton HungrySingleton::m_instance;

//int main()
//{
//	HungrySingleton* hs1 = HungrySingleton::GetInstance();
//	HungrySingleton* hs2 = HungrySingleton::GetInstance();
//	HungrySingleton* hs3 = HungrySingleton::GetInstance();
//	HungrySingleton* hs4 = hs3->GetInstance();
//	cout << hs1 << endl;
//	cout << hs2 << endl;
//	cout << hs3 << endl;
//	cout << hs4 << endl;
//	system("pause");
//	return 0;
//}

#include <mutex>
#include <thread>
#include <vector>
class LazySingleton
{
public:
	static LazySingleton* GetInstance()
	{
		if (m_pInstrance == nullptr)
		{
			_mtx.lock();
			if (m_pInstrance == nullptr)
			{
				m_pInstrance = new LazySingleton();
			}
			_mtx.unlock();
		}
		return m_pInstrance;
	}
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (LazySingleton::m_pInstrance)
			{
				delete LazySingleton::m_pInstrance;
				cout << "~CGarbo()" << endl;
			}
		}
	};
	static CGarbo Garbo;
private:
	LazySingleton(){};
	LazySingleton(const LazySingleton&) = delete;
	LazySingleton& operator=(const LazySingleton&) = delete;
	static LazySingleton* m_pInstrance;
	static mutex _mtx;
};
LazySingleton* LazySingleton::m_pInstrance = nullptr;
LazySingleton::CGarbo Garbo;
mutex LazySingleton::_mtx;

void func(int n){
	cout << LazySingleton::GetInstance() << endl;
}

int main()
{
	vector<thread> v;
	for (int i = 0; i < 1000; i++){
		v.push_back(thread(func, 10));
	}

	for (int i = 0; i < 1000; i++){
		v[i].join();
	}

	return 0;
}

#endif