#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
template <class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(2.0, 3.0) << endl;
	cout << Add((double)1, 2.0) << endl;	//��ʽʵ����
	cout << Add<int>(7, 8.0) << endl;		//��ʽʵ����
	system("pause");
	return 0;
}

#endif

#if 0
//ͨ�üӷ�����
template <class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

//ר�Ŵ���int�ļӷ�����
int Add(const int left, const int right)
{
	return left + right;
}

int main()
{
	Add(1, 3);			//���ģ�庯��ƥ�䣬����������Ҫת��
	Add<int>(1, 2);		//���ñ�����ת����Add�汾
	system("pause");
	return 0;
}
#endif

#if 0
//ר�Ŵ���int�ļӷ�����
int Add(const int left, const int right)
{
	return left + right;
}

//ͨ�üӷ�����
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);		//��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 1.0);	//����ģ��������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
	return 0;
}
#endif

#if 0
#include <assert.h>
//��̬˳���
template <class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pDate(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	//����������������������������ʾ
	~Vector();

	void PushBack(const T& data)
	{
		//CheckCapacity();
		_pDate[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pDate[pos];
	}
private:
	T* _pDate;
	size_t _size;
	size_t _capacity;
};

//������������
//ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Vector <T>::~Vector()
{
	if (_pDate)
	{
		delete[] _pDate;
	}
}

int main()
{
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);

	Vector<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);

	for (size_t i = 0; i < s1.Size(); i++){
		cout << s1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < s2.Size(); ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

//������String�����ز���
#include <string>

void TestString()
{
	string s1;		//����յ� string�����s1
	string s2("hello world");	//�� C ��ʽ�ַ�������string�����s2
	string s3(10, 'a');			//��ʮ���ַ�'a'����string�����s3
	string s4(s2);				//��������s4
	string s5(s3, 5);			//��s3��ǰ5���ַ���������string�����s5
	string s6(s2, 0, 5);		//��s2��0��5���ַ�����s6
	string s7("come on", 4);	//��"come on"��ǰ4���ַ�����s7
}
#if 0
int main()
{
	TestString();
	return 0;
}
#endif

#if 0
//string�������������
//size/length/clear/resize
void Teststring1()
{
	//ע�⣺string�����֧���� cin �� cout ������������
	string s("come on wg");
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s�е��ַ�����գ�ע�����ֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	//����Ч�ַ��ĸ������ӵ�15�������������'b'���
	//"bbbbbbbbbbbbbbb"
	s.resize(15, 'b');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//����Ч�ַ��ĸ������ӵ�20�������������ȱʡֵ'\0'���
	//"bbbbbbbbbbbbbbb\0\0\0\0\0"
	//ע���ʱs����Ч�ַ������Ѿ��ﵽ20��
	s.resize(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s����Ч�ַ��������ٵ�5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void TestString2()
{
	string s;
	//����reserve�Ƿ��ı�string����ЧԪ�ظ���(����)
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С(����)
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}


int main()
{
	Teststring1();
	//TestString2();
	system("pause");
	return 0;
}
#endif

