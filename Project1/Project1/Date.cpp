#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date {
public:    
	//构造
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > GetDay(year, month))
		{
			cout << "非法日期，已设置为默认值：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//获取天数以便后面进位
	int GetDay(int year, int month)
	{
		//有12个月
		static int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month - 1];
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				day++;
			}
		}
		return day;
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
	Date& operator+=(int days)
	{
		if (days < 0)
			return *this -= -days;
		_day += days;
		//然后判断当前天数是否大于当月天数
		while(_day > GetDay(_year, _month))
		{
			//减去当月天数
			_day -= GetDay(_year, _month);
			//月份进位
			++_month;
			//判断月份是否合理
			if (_month == 13)
			{
				//如果月份超限，年份进位，月份变为一月
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date& operator-=(int days)
	{
		if (days < 0)
			return *this += -days;
		_day -= days;
		while (_day <= 0)
		{
			--_month;
			if (_month <= 0){
				_month = 12;
				--_year;
			}
			_day += GetDay(_year, _month - 1);
		}
		//cout << _year << _month << _day << endl;
		return *this;
	}
	Date operator+(int days)
	{
		Date ret(*this);
		ret += days;
		return ret;
	}
	Date operator-(int days)
	{
		Date ret(*this);
		ret -= days;
		return ret;
	}
	int operator-(const Date& d)
	{
		Date d1(*this);
		Date d2(d);
		int day = 0;
		if (d1 > d2)
		{
			while (d1 > d2)
			{
				--d1;
				++day;
			}
			return day;
		}
		else
		{
			while (d1 < d2)
			{
				++d1;
				++day;
			}
			return -day;
		}
	}
	//++date
	Date& operator++()
	{
		return *this += 1;
	}
	//date++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	//--date
	Date& operator--()
	{
		return *this -= 1;
	}
	//date--
	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	bool operator>(const Date& d)const
	{
		return _year > d._year || 
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day == d._day;
	}
	bool operator>=(const Date& d)const
	{
		return (*this > d) || (*this == d);
	}
	bool operator<(const Date& d)const
	{
		return _year < d._year ||
			_year == d._year && _month < d._month ||
			_year == d._year && _month == d._month && _day < d._day;

	}
	bool operator<=(const Date& d)const
	{
		return (*this < d) || (*this == d);
	}
	bool operator==(const Date& d)const
	{
		return (_year == d._year) 
			&& (_month == d._month) 
			&& (_day == d._day);
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
private:    
	int _year;    
	int _month;    
	int _day;
};

int main()
{
	Date d1(2018, 9, 9);
	d1 -= 30;
	system("pause");
	return 0;
}