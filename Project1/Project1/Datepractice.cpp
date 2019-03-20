#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date {
public:
	//构造
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month > 12 || day > GetDay(year, month)){
			cout << "输入日期非法，已将日期设置为默认值：1900-1-1" << endl;
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
		static int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month - 1];
		if (month == 2){
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
				day++;
			}
		}
		return day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date& operator+=(int days)
	{
		_day += days;
		while (_day > GetDay(_year, _month)){
			_day -= GetDay(_year, _month);
			++_month;
			if (_month == 13){
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date& operator-=(int days);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	//++date
	Date& operator++();
	//date++
	Date operator++(int);
	//--date
	Date& operator--();
	//date--
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
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