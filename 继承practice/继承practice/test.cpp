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
		//cout << Person::_age << endl;		//�����private��Ա����������ô�̳ж����ɼ�
		cout << "_stunum:" << _stunum << endl;
		cout << "Person::_stunum:" << Person::_name << endl;
	}
protected:
	string _name = "linda";
	int _stunum = 123;	//ѧ��
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
//������������������ĸ�ֵ��ϵ
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
	////s = p;	//ֻ�������������������ֵ������Կ�����Ƭ������Ķ��ˣ�
	//			//���ǻ�������ܸ����������ֵ����Ŀ��Ը��ٵĸ�ֵ���ٵĲ��ܸ���ĸ�ֵ
	//Person *pobj = &s;	//��������󸳸�����ָ��
	////s.Set();
	////pobj->Print();

	//Person& rp = s;	//��������󸳸���������
	//s.Set();
	//rp.Print();

	////Student *sobj = &p;	//��ͨ����ָ�벻�ܸ���������ָ��
	////�����ָ��ͨ��ǿ������ת�������������ָ��
	//pobj = &p;
	//Student *s1 = (Student*)pobj;
	////s1->_id = 10;
	//s1->Print();

	Student sobj;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.��������ܸ�ֵ�����������
	//sobj = pobj;
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sobj;
	Student *ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
	ps1->_id = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
		//:_name(new string[strlen(name) + 1])	//����ĳ�Ա����ʹ�ø���Ĺ��캯����ʼ��
		:Person(name)	//�������û��Ĭ�Ϲ��캯�����͵������ˣ��͵���ʾ���ø��๹�캯��
	{
		_name = name;
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		:Person(s)	//�������ʽ���ø��࿽�����캯������ô������������ÿ�������,�����Ĭ�Ϲ��캯��
	{
		//����Ŀ����������ʵ�֣����򲻻�����࿽�����죬�ᱨ��
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
//����˽��
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
//c++11 final�ؼ���
class NonInherit final
{};

class stu : public NonInherit
{};
#endif

#if 0
//���μ̳�
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