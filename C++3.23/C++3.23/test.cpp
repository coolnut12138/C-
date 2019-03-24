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
	cout << Add((double)1, 2.0) << endl;	//隐式实例化
	cout << Add<int>(7, 8.0) << endl;		//显式实例化
	system("pause");
	return 0;
}

#endif

#if 0
//通用加法函数
template <class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

//专门处理int的加法函数
int Add(const int left, const int right)
{
	return left + right;
}

int main()
{
	Add(1, 3);			//与非模板函数匹配，编译器不需要转化
	Add<int>(1, 2);		//调用编译器转化的Add版本
	system("pause");
	return 0;
}
#endif

#if 0
//专门处理int的加法函数
int Add(const int left, const int right)
{
	return left + right;
}

//通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);		//与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 1.0);	//函数模板可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
	return 0;
}
#endif

#if 0
#include <assert.h>
//动态顺序表
template <class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pDate(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	//析构函数在类中声明，在类外演示
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

//定义析构函数
//注意：类模板中函数放在类外进行定义时，需要加模板参数列表
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

//下面是String类的相关操作
#include <string>

void TestString()
{
	string s1;		//构造空的 string类对象s1
	string s2("hello world");	//用 C 格式字符串构造string类对象s2
	string s3(10, 'a');			//用十个字符'a'构造string类对象s3
	string s4(s2);				//拷贝构造s4
	string s5(s3, 5);			//用s3中前5个字符拷贝构造string类对象s5
	string s6(s2, 0, 5);		//用s2的0到5个字符构造s6
	string s7("come on", 4);	//用"come on"的前4个字符构造s7
}
#if 0
int main()
{
	TestString();
	return 0;
}
#endif

#if 0
//string类对象容器操作
//size/length/clear/resize
void Teststring1()
{
	//注意：string类对象支持用 cin 和 cout 进行输入和输出
	string s("come on wg");
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中的字符串清空，注意清空只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	//将有效字符的个数增加到15个，多出来的用'b'填充
	//"bbbbbbbbbbbbbbb"
	s.resize(15, 'b');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将有效字符的个数增加到20个，多出来的用缺省值'\0'填充
	//"bbbbbbbbbbbbbbb\0\0\0\0\0"
	//注意此时s中有效字符个数已经达到20个
	s.resize(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中有效字符个数减少到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void TestString2()
{
	string s;
	//测试reserve是否会改变string中有效元素个数(不会)
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//测试reserve参数小于string的底层空间大小时，是否会将空间缩小(不会)
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

