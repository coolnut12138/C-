#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	Date(int year = 1900, int month = 1, int day = 1)
	{
		//判断日期合法性
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > Getday(year, month))
		{
			cout << "输入日期不合法，已将日期修改为默认值：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	int Getday(int year, int month)
	{
		static int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int day = days[month - 1];
		if (2 == month){
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
				day++;
			}
		}
		return day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date& operator+=(int day)
	{
		if (day < 0){
			return *this -= -day;
		}
		_day += day;
		while (_day >= Getday(_year, _month)){
			_day -= Getday(_year, _month);
			++_month;
			if (_month == 13){
				_month = 1;
				++_year;
			}
		}
		return *this;
	}

	Date& operator-=(int day)
	{
		if (day < 0){
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0){
			--_month;
			if (_month == 0){
				--_year;
				_month = 12;
			}
			_day += Getday(_year, _month);
		}
		return *this;
	}

	Date operator-(int days)
	{
		Date ret(*this);
		ret -= days;
		return ret;
	}

	Date operator+(int days)
	{
		Date ret(*this);
		ret += days;
		return ret;
	}
	
	//d1 - d2
	int operator-(const Date& d)
	{
		Date d1(*this);
		Date d2(d);
		int day = 0;
		int flag = 1;
		if (d1 < d2){
			//d1 < d2,调换位置，将符号位改变
			d1 = d2;
			d2 = *this;
			flag = -1;
		}
		while (d2 < d1)
		{
			d2++;
			++day;
		}
		return flag * day;
	}
	//++d
	Date& operator++()
	{
		return *this += 1;
	}
	//d++
	Date& operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date& operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	bool operator<(const Date& d)
	{
		return _year < d._year
			|| _year == d._year && _month < d._month
			|| _year == d._year && _month == d._month && _day < d._day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator<=(const Date& d)
	{
		return (*this < d) || (*this == d);
	}

	bool operator>(const Date& d)
	{
		return !(*this < d && *this == d);
	}

	bool operator>=(const Date& d)
	{
		return (*this > d) || (*this == d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void Test()
{
	Date d1(2019, 5, 21);
	cout << d1 << endl;
	Date d2(d1);
	cout << d2 << endl;
	//d1 += 2;
	d2 -= 3;
	cout << d1 + 11 << endl;
	cout << d2 << endl;
	d1 += 365;
	d2 -= 365;
	cout << d1 << endl;
	cout << d2 << endl;

	cout << (d1 - d2) << endl;

	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}