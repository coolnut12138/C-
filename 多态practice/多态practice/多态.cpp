#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#if 0
class Person 
{
public:
	void BuyTicket() { cout << "����" << endl;}
};
class Student : public Person
{
public:
	void BuyTicket() { cout << "��shi" << endl;}
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
	Func(s);	//������ᷢ����Ƭ�Ĳ��������൱�ڴ���һ��������󣬵��õ��Ǹ���ĺ�����������������ͬ

	system("pause");
	return 0;
}
#endif

//class Person
//{
//public:
//	virtual Person* BuyTicket() { cout << "����" << endl; return new Person; }
//};
//class Student : public Person
//{
//public:
//	virtual Student* BuyTicket() { cout << "��shi" << endl; return new Student; }
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
//	virtual void BuyTicket() { cout << "����" << endl; };
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "��shi" << endl; }
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

////�����ࣺ���崿�麯���������಻��ʵ����������Ϊ�������еĺ����Ǵ��麯�����ǲ������ġ����ֽӿڼ̳С�
//class Person
//{
//public:
//	//���麯��
//	virtual void BuyTicket() = 0;
//};
////�����б���ʵ�ָ���Ĵ��麯������������Ҳ�ǳ����࣬����ʵ��������
//class Student : public Person
//{
//public:
//	//ʵ�ָ���Ĵ��麯��
//	virtual void BuyTicket() { cout << "��shi" << endl; }
//};
//
//int main()
//{
//	Person p;	//�����಻��ʵ����
//	Student s;
//	return 0;
//}

////1.final ���λ�����麯�����ܱ���������д������ʵ�ּ̳�
//class Car
//{
//public:
//	virtual void Drive() final{}
//};
//class Benz :public Car
//{
//public:
//	//virtual void Drive() { cout << "������д" << endl; }
//};

////���麯�� + override = ǿ����д���෽��
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	//��������ຯ����������ֵ��������ͬ
//	virtual void Drive() override { cout << "������д" << endl; }
//};
//class Bmw :public Car
//{
//public:
//	//��������ຯ����������ֵ��������ͬ
//	virtual void Drive() override { cout << "������д" << endl; }
//};


//class Car
//{
//public:
//	virtual void Drive() { cout << "Car" << endl; };
//	//�麯����ָ�룺_vfptr
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override { cout << "Benz" << endl; }
//	//�麯����ָ�룺_vfptr,��ʵ�ǴӸ���̳й�����
//};
//class Bmw :public Car
//{
//public:
//	virtual void Drive() override { cout << "BMW" << endl; }
//	//�麯����ָ�룺_vfptr,��ʵ�ǴӸ���̳й�����
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

//�ѣ�ջ�����ݶΣ������
int global = 10;	//���ݶ�
int main()
{
	int a = 1;	//ջ
	int* pa = new int;	//��
	char* str = "123";	//�����
	Base b;
	//��ȡ���ָ������ݣ�ָ�������׵�ַ
	cout << "���ݶΣ�" << &global << endl;
	cout << "ջ��" << &a << endl;
	cout << "�ѣ�" << pa << endl;
	//cout << "����Σ�" << str << endl;
	printf("����Σ� %p\n", str);
	cout << "���:" << ((int*)*((int*)&b)) << endl;
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