#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
//protected:
	string _name = "mark";
	int _age = 18;
};

class Student : public Person
{
public:
	void fun()
	{
		_name = "asd";
		_age = 20;
	}
};

int main()
{
	Person p;
	p.Print();
	Student s;
	s._name = "sad";
	s.Print();
	system("pause");
	return 0;
}
#endif

#if 0
class Person
{
public:
	void Print()
	{
		cout << "Person _name:" << _name << endl;
		cout << "_age:" << _age << endl;
	}
protected:
	string _name = "mark";
private:
	int _age = 456;
};

class Student : public Person
//class Student : protected Person
//class Student : private Person
{
public:
	void Print()
	{
		cout << "_name:" << _name << endl;
		//cout << _age << endl;
		//cout << Person::_age << endl;		//父类的private成员在子类中怎么继承都不可见
		cout << "_stunum:" << _stunum << endl;
		cout << "Person::_stunum:" << Person::_name << endl;
	}
protected:
	string _name = "linda";
	int _stunum = 123;	//学号
};

int main()
{
	Person p;
	p.Print();
	Student s;
	s.Print();
	system("pause");
	return 0;
}
#endif

#if 0
//基类对象和派生类对象间的赋值关系
class Person
{
public:
	void Print()
	{
		cout << _name << endl;
		cout << _gender << endl;
		cout << _age << endl;
	}
protected:
	string _name = "mark";
	string _gender = "male";
	int _age = 18;
};

class Student : public Person
{
public:
	void Set()
	{
		_name = "lv";
		_gender = "female";
		_age = 20;
	}
	void Print()
	{
		cout << _name << endl;
		cout << _gender << endl;
		cout << _age << endl;
		cout << _id << endl;
	}
protected:
	int _id = 999;
};

int main()
{
	//Student s;
	//Person p = s;
	////s.Print();	
	////s = p;	//只能派生类对象给基类对象赋值，这可以看成切片，多余的丢了，
	//			//但是基类对象不能给派生类对象赋值，多的可以给少的赋值，少的不能给多的赋值
	//Person *pobj = &s;	//派生类对象赋给基类指针
	////s.Set();
	////pobj->Print();

	//Person& rp = s;	//派生类对象赋给基类引用
	//s.Set();
	//rp.Print();

	////Student *sobj = &p;	//普通基类指针不能赋给派生类指针
	////基类的指针通过强制类型转换赋给派生类的指针
	//pobj = &p;
	//Student *s1 = (Student*)pobj;
	////s1->_id = 10;
	//s1->Print();

	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj;
	Student *ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_id = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_id = 10;

	system("pause");
	return 0;
}
#endif

#if 0
class Person
{
public:
	Person(const string name = "mark")
		:_name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p){
			_name = p._name;
		}
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};

class Student : public Person
{
public:
	Student(string name = "lzl")
		//:_name(new string[strlen(name) + 1])	//父类的成员必须使用父类的构造函数初始化
		:Person(name)	//如果父类没有默认构造函数，就调不动了，就得显示调用父类构造函数
	{
		_name = name;
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		:Person(s)	//如果不显式调用父类拷贝构造函数，那么编译器不会调用拷贝构造,会调用默认构造函数
	{
		//子类的拷贝构造必须实现，否则不会调父类拷贝构造，会报错
		_name = s._name;
	}
};

int main()
{
	Student s;
	Student copy(s);
	
	return 0;
}

#endif

#if 0
//构造私有
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit(){}
};
//c++11 final关键字
class NonInherit final
{};

class stu : public NonInherit
{};
#endif

#if 0
//菱形继承
class Person
{
public:
	string _name;
};

class Student : virtual public Person
{
protected:
	int _num;
};

class Teacher : virtual public Person
{
protected:
	int _id;
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse;
};

void Test()
{
	Assistant a;
	a._name = "mark";
	a.Teacher::_name = "lzl";
	a.Student::_name = "linda";
}

int main()
{
	Test();
	system("pause");
	return 0;
}
#endif

class A
{
public:
	int _a;
};
 //class B : public A
class B : virtual public A
{
public:
	int _b;
};
 //class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}