#define _CRT_SECURE_NO_WARNINGS 1
//����ģ����ϰ
#include <iostream>
using namespace std;

#if 0
template<typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);
	cout << a << endl;
	cout << b << endl;

	double a1 = 2.01, b1 = 3.02;
	Swap(a1, b1);
	cout << a1 << " " << b1 << endl;
	return 0;
}
#endif

#if 0
template<class T>
//�����ӷ���������������
T Add(const T& left, const T& right)
{
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.01;
	cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;
	//cout << Add(a1, d1) << endl;	//�������ͱ�������֪���������
	cout << Add(a1, (int)d1) << endl;	//�������ԣ�����ǿת
	cout << Add((double)a1, d1) << endl;	//�������ԣ�����ǿת
	cout << Add<double>(a1, d1) << endl;	//��ʽʵ����
	return 0;
}
#endif
#if 0
//test ���ڵ�swap����
int main()
{
	int a = 1, b = 2;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
#endif

#if 0
#include <assert.h>
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_array(new T[capacity])	//��Ա������ʼ��˳��ֻ������˳���й�
		, _size(0)
		, _capacity(capacity)
	{}

	void PushBack(const T& x)
	{
		if (_size == _capacity){
			cout << "FULL" << endl;
			return;
		}
		_array[_size] = x;
		++_size;
	}

	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];	//�˴������ã�T&�������Է��ص��Ǳ����ı��������������ⱻ�޸ģ�
				//����Ǵ�ֵ����ô�ں����з��صľ�����ʱ����������ʱ�������г��ԣ����Բ��������ⱻ�޸�
	}

	void PopBack()
	{
		if ()
		{

		}
		int
	}

	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

int main()
{
	Vector<int> v1;
	Vector<char> v2;

	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	for (size_t i = 0; i < v1.Size(); i++){
		if (v1[i] % 2 == 0){
			v1[i] = v1[i] * 2;
		}
	}

	for (size_t i = 0; i < v1.Size(); i++){
		cout << v1[i] << endl;
	}
	return 0;
}
#endif

#include <string>

//int main()
//{
//	string s1;
//	string s2("hello");
//	string s3(10, 'a');
//	string copy(s3);
//
//	s1 = copy;
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << copy << endl;
//	
//	return 0;
//}

int main()
{
	string s1;
	s1.push_back('h');
	s1.push_back('e');
	s1.push_back('l');
	s1.push_back('l');
	s1.push_back('o');

	s1.append("world");
	
	cout << s1 << endl;

	s1 += "hello world";
	s1 += '!';

	s1 += s1;
	cout << s1 << endl;
	return 0;
}