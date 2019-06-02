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
		cout << "体积为：" << endl;
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
	cout << "请输入1号长、宽、高" << endl;
	cin >> len >> wid >> hei;
	cu1.Set(len, wid, hei);
	cu1.Bulk();
	cout << "请输入2号长、宽、高" << endl;
	cin >> len >> wid >> hei;
	cu2.Set(len, wid, hei);
	cu2.Bulk();
	cout << "请输入3号长、宽、高" << endl;
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
	int _ceng;	//层数
	int _num;	//房间数
	int _area;	//总面积
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
	int bedRoom_num;	//卧室数
	int living_num;		//客厅数
	int bathRoom_num;	//卫生间数
	int kitchRoom_num;		//厨房数
};
class Office_Building :public Building
{
public:
	Office_Building(int off = 21, int meet = 20)
		:Office_num(off)
		,meetingRoom_num(meet)
	{}
	int Office_num;	//办公室数
	int meetingRoom_num;	//会议室
};
class Hospital :public Building
{
public:
	Hospital(int roo = 22, int ope = 33)
		:_Room(roo)
		,_operatorRoom(ope)
	{}
	int _Room;	//病房数
	int _operatorRoom;	//手术室
};

int main()
{
	Building b;
	cout << "层数:" << b._ceng << "房间数：" << b._num << "面积：" << b._area << endl;
	Home_Arch h;
	cout << "卧室数:" << h.bedRoom_num << "客厅数：" << h.living_num << "卫生间数：" << h.bathRoom_num << "厨房数：" << h.kitchRoom_num << endl;
	Office_Building o;
	cout << "办公室数:" << o.Office_num << "会议室数：" << o.meetingRoom_num << endl;
	Hospital ho;
	cout << "病房数:" << ho._Room << "手术室数：" << ho._operatorRoom << endl;
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
	Teacher(string name = "张三", int mon = 8000, int hour = 30)
	{
		_name = name;
		_money = mon;
		_hours = hour;
	}
	void Print()
	{
		cout << "姓名：" << _name << "月工资：" << _money << "授课时数：" << _hours << endl;
	}
	string _name;	//名字
	int _money;		//月工资
	int _hours;
};

class Professor: public Teacher
{
public:
	Professor(string name = "李四", int mon = 6000, int hour = 30)
	{
		_name = name;
		_money = mon;
		_hours = hour;
	}
	void ProMoney()
	{
		cout << "教授：" << _name << "工资为：" << _money + _hours*30 << endl;
	}
};

class Lecturer: public Teacher
{
public:
	Lecturer(string name = "王五", int mon = 4000, int hour = 20)
	{
		_name = name;
		_money = mon;
		_hours = hour;
	}
	void LecMoney()
	{
		cout << "讲师：" << _name << "工资为：" << _money + _hours*20 << endl;
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
		cout << "年龄：" << _age << endl;
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
		cout << "正方形周长：" << _width * 4 << endl;
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
		cout << "长方形周长：" << 2 * (_width + _width2) << endl;
	}
	void Print2()
	{
		cout << "宽：" << _width << endl;
		cout << "长：" << _width2 << endl;
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