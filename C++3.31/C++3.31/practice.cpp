#define _CRT_SECURE_NO_WARNINGS 1
//函数模板练习
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
//两个加法函数不构成重载
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
	//cout << Add(a1, d1) << endl;	//这种类型编译器不知道如何推演
	cout << Add(a1, (int)d1) << endl;	//这样可以，类型强转
	cout << Add((double)a1, d1) << endl;	//这样可以，类型强转
	cout << Add<double>(a1, d1) << endl;	//显式实例化
	return 0;
}
#endif
#if 0
//test 库内的swap函数
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
		:_array(new T[capacity])	//成员变量初始化顺序只与声明顺序有关
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
		return _array[index];	//此处是引用（T&），所以返回的是变量的别名，可以在类外被修改，
				//如果是传值，那么在函数中返回的就是临时变量，而临时变量具有常性，所以不能在类外被修改
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