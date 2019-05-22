#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#if 0
class Person 
{
public:
	void BuyTicket() { cout << "吃肉" << endl;}
};
class Student : public Person
{
public:
	void BuyTicket() { cout << "吃shi" << endl;}
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person p;
	Student s;

	Func(p);
	Func(s);	//传子类会发生切片的操作，就相当于传了一个父类对象，调用的是父类的函数，所以输出结果相同

	system("pause");
	return 0;
}
#endif

//class Person
//{
//public:
//	virtual Person* BuyTicket() { cout << "吃肉" << endl; return new Person; }
//};
//class Student : public Person
//{
//public:
//	virtual Student* BuyTicket() { cout << "吃shi" << endl; return new Student; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	Func(p);
//	Func(s);
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "吃肉" << endl; };
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "吃shi" << endl; }
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Person* ps = new Student;
//	delete ps;
//	system("pause");
//	return 0;
//}

////抽象类：定义纯虚函数，抽象类不能实例化对象，因为抽象类中的函数是纯虚函数，是不完整的。体现接口继承。
//class Person
//{
//public:
//	//纯虚函数
//	virtual void BuyTicket() = 0;
//};
////子类中必须实现父类的纯虚函数，否则子类也是抽象类，不能实例化对象。
//class Student : public Person
//{
//public:
//	//实现父类的纯虚函数
//	virtual void BuyTicket() { cout << "吃shi" << endl; }
//};
//
//int main()
//{
//	Person p;	//抽象类不能实例化
//	Student s;
//	return 0;
//}

////1.final 修饰基类的虚函数不能被派生类重写，体现实现继承
//class Car
//{
//public:
//	virtual void Drive() final{}
//};
//class Benz :public Car
//{
//public:
//	//virtual void Drive() { cout << "不能重写" << endl; }
//};

////纯虚函数 + override = 强制重写基类方法
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	//必须与基类函数名、返回值、参数相同
//	virtual void Drive() override { cout << "必须重写" << endl; }
//};
//class Bmw :public Car
//{
//public:
//	//必须与基类函数名、返回值、参数相同
//	virtual void Drive() override { cout << "必须重写" << endl; }
//};


//class Car
//{
//public:
//	virtual void Drive() { cout << "Car" << endl; };
//	//虚函数表指针：_vfptr
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override { cout << "Benz" << endl; }
//	//虚函数表指针：_vfptr,其实是从父类继承过来的
//};
//class Bmw :public Car
//{
//public:
//	virtual void Drive() override { cout << "BMW" << endl; }
//	//虚函数表指针：_vfptr,其实是从父类继承过来的
//};
//
//void Func(Car& c)
//{
//	c.Drive();
//}
//
//int main()
//{
//	Car c;
//	Benz benz;
//	Bmw bmw;
//
//	Func(c);
//	Func(benz);
//	Func(bmw);
//	system("pause");
//	return 0;
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
};

//堆，栈，数据段，代码段
int global = 10;	//数据段
int main()
{
	int a = 1;	//栈
	int* pa = new int;	//堆
	char* str = "123";	//代码段
	Base b;
	//获取虚表指针的内容：指向虚表的首地址
	cout << "数据段：" << &global << endl;
	cout << "栈：" << &a << endl;
	cout << "堆：" << pa << endl;
	//cout << "代码段：" << str << endl;
	printf("代码段： %p\n", str);
	cout << "虚表:" << ((int*)*((int*)&b)) << endl;
	system("pause");
	return 0;
}

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int arr[10240] = { 0 };
	int len = 0;
	while (cin >> n){
		v.push_back(n);
		if (cin.get() == '\n'){
			break;
		}
	}
	len = v.size() / 2;
	auto begin = v.begin();
	while (begin != v.end()){
		arr[*begin]++;
		begin++;
	}
	for (int i = 0; i < 10240; i++){
		if (arr[i] > len){
			cout << i << endl;
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, res, cur;
	getline(cin, str);
	for (size_t i = 0; i <= str.size(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			cur += str[i];
		}
		else{
			if (res.size() < cur.size()){
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}
#endif