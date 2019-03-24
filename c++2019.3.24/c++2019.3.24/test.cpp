#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		, r(year)
		, _c(10)
		, _t(11, 55, 1)
	{}
private:
	int _year;
	int _month;
	int _day;
	int& r;
	const int _c;
	Time _t;
};

int main()
{
	Date d1;
	Date d(d1);
	return 0;
}
#endif

#if 0
class Date
{
public:
	 explicit Date (int year)
		: _year(year)
	{
		cout << "Date(int):" << this << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << " = " << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019);
	d1 = 2020;
}

int main()
{
	TestDate();
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour = 10, int minute = 10, int second = 10)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
private:
	int _year;
	int _month;
	int _day;
	Time _c;
};
int main()
{
	Date d;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		_count++;
	}

	Test(Test& t)
	{
		_count++;
	}

	~Test()
	{
		--_count;
	}

	static int Getconut()
	{
		return _count;
	}
private:
	int _t;
	static int _count;
};

int Test::_count = 0;
void TestFunc()
{
	Test t1;
	Test t2(t1);
}

int main()
{
	//Test t1, t2;
	//cout << sizeof(Test) << endl;	//是4，对象里面没有包含静态变量，所以是4
	//cout << t1._count << endl;
	//cout << t2._count << endl;
	//cout << Test::_count << endl;

	//cout << &t1._count << " " << &t2._count << " " << &Test::_count << endl;

	cout << Test::Getconut() << endl;
	Test t;
	TestFunc();
	cout << Test::Getconut() << endl;
	system("pause");
	return 0;
}
#endif

//日期转天数oj
class CSum
{
public:
	CSum()
	{
		_count++;
		_sum += _count;
	}

	static size_t GetSum()
	{
		return _sum;
	}
	
	static void ReSetSum()
	{
		_count = 0;
		_sum = 0;
	}
private:
	static size_t _sum;
	static size_t _count;
};
//静态变量在类外初始化
size_t CSum::_sum = 0;
size_t CSum::_count = 0;

size_t Sum(size_t N)
{
	CSum::ReSetSum();
	CSum s[100];
	return CSum::GetSum();
}

int main()
{
	cout << Sum(100) << endl;
	system("pause");
	return 0;
}