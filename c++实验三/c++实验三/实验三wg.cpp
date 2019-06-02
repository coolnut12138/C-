#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

class Cuboid
{
public:
	void Set(int length, int width, int heigth)
	{
		_length = length;
		_width = width;
		_height = heigth;
	}
	void Bulk()
	{
		cout << "���Ϊ��" << endl;
		cout << _length * _width * _height << endl;
	}
private:
	int _length;
	int _width;
	int _height;
};

int main()
{
	int len, wid, hei;
	Cuboid cu1;
	Cuboid cu2;
	Cuboid cu3;
	cout << "������1�ų�������" << endl;
	cin >> len >> wid >> hei;
	cu1.Set(len, wid, hei);
	cu1.Bulk();
	cout << "������2�ų�������" << endl;
	cin >> len >> wid >> hei;
	cu2.Set(len, wid, hei);
	cu2.Bulk();
	cout << "������3�ų�������" << endl;
	cin >> len >> wid >> hei;
	cu3.Set(len, wid, hei);
	cu3.Bulk();
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Building
{
public:
	Building(int cen = 10, int num = 100, int are = 1000)
		:_ceng(cen)
		,_num(num)
		,_area(are)
	{}
	int _ceng;	//����
	int _num;	//������
	int _area;	//�����
};
class Home_Arch :public Building
{
public:
	Home_Arch(int bed = 10, int liv = 12, int bat = 13, int kit = 14)
		:bedRoom_num(bed)
		,living_num(liv)
		,bathRoom_num(bat)
		,kitchRoom_num(kit)
	{}
	int bedRoom_num;	//������
	int living_num;		//������
	int bathRoom_num;	//��������
	int kitchRoom_num;		//������
};
class Office_Building :public Building
{
public:
	Office_Building(int off = 21, int meet = 20)
		:Office_num(off)
		,meetingRoom_num(meet)
	{}
	int Office_num;	//�칫����
	int meetingRoom_num;	//������
};
class Hospital :public Building
{
public:
	Hospital(int roo = 22, int ope = 33)
		:_Room(roo)
		,_operatorRoom(ope)
	{}
	int _Room;	//������
	int _operatorRoom;	//������
};

int main()
{
	Building b;
	cout << "����:" << b._ceng << "��������" << b._num << "�����" << b._area << endl;
	Home_Arch h;
	cout << "������:" << h.bedRoom_num << "��������" << h.living_num << "����������" << h.bathRoom_num << "��������" << h.kitchRoom_num << endl;
	Office_Building o;
	cout << "�칫����:" << o.Office_num << "����������" << o.meetingRoom_num << endl;
	Hospital ho;
	cout << "������:" << ho._Room << "����������" << ho._operatorRoom << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
	Teacher(string name = "����", int mon = 8000, int hour = 30)
	{
		_name = name;
		_money = mon;
		_hours = hour;
	}
	void Print()
	{
		cout << "������" << _name << "�¹��ʣ�" << _money << "�ڿ�ʱ����" << _hours << endl;
	}
	string _name;	//����
	int _money;		//�¹���
	int _hours;
};

class Professor: public Teacher
{
public:
	Professor(string name = "����", int mon = 6000, int hour = 30)
	{
		_name = name;
		_money = mon;
		_hours = hour;
	}
	void ProMoney()
	{
		cout << "���ڣ�" << _name << "����Ϊ��" << _money + _hours*30 << endl;
	}
};

class Lecturer: public Teacher
{
public:
	Lecturer(string name = "����", int mon = 4000, int hour = 20)
	{
		_name = name;
		_money = mon;
		_hours = hour;
	}
	void LecMoney()
	{
		cout << "��ʦ��" << _name << "����Ϊ��" << _money + _hours*20 << endl;
	}
};

int main()
{
	Professor p;
	p.ProMoney();
	Lecturer l;
	l.LecMoney();
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class Animal
{
protected:
	int _age;
};

class dog :public Animal
{
public:
	void SetAge()
	{
		_age = 10;
	}
	void Print()
	{
		cout << "���䣺" << _age << endl;
	}
};

int main()
{
	dog d;
	d.SetAge();
	d.Print();
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

class vehicle
{
public:
	int MaxSpeed;
	int Weight;
	void Run()
	{}
	void Stop()
	{}
};

class bicycle: virtual public vehicle
{
protected:
	int Height;
};

class motorcar: virtual public vehicle
{
protected:
	int SeatNum;
};

class motorcycle: public bicycle, public motorcar
{
public:
	void Print()
	{
		cout << MaxSpeed << " " << Weight << endl;
	}
};

int main()
{
	motorcycle m;
	m.MaxSpeed = 20;
	m.Weight = 10;
	m.Print();
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Square
{
public:
	Square()
	{
		_width = 2;
	}

	virtual void Print()
	{
		cout << "�������ܳ���" << _width * 4 << endl;
	}
protected:
	int _width;
};

class Rectangle :public Square
{
public:
	Rectangle()
	{
		_width2 = 3;
	}
	virtual void Print()
	{
		cout << "�������ܳ���" << 2 * (_width + _width2) << endl;
	}
	void Print2()
	{
		cout << "��" << _width << endl;
		cout << "����" << _width2 << endl;
	}
protected:
	int _width2;
};

void Func(Square* s)
{
	s->Print();
}
int main()
{
	Square s;
	Rectangle r;
	Func(&s);
	Func(&r);
	return 0;
}
#endif