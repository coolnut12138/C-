#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	//����
	Date(int year = 1900, int month = 1, int day = 1)
	{
		//�жϼ������ںϷ���
		if (year <= 0 || month <= 0 || month > 12
			|| day <= 0 || day > Getday(year, month))
		{
			cout << "�������ڷǷ����ѽ���������ΪĬ��ֵ 1900-1-1" << endl;
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
		//��̬�ֲ�����Ĭ�ϳ�ʼֵΪ0�����������Ϊ��ʼ��ִֻ��һ�Σ�����ĳ�ʼ����������ִ�С�
		//����ͨ�ֲ�������ʼֵ���������ÿһ�κϷ���ʼ������ִ�С�
		static int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month - 1];
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| (year % 400 == 0)){
				day++;
			}
		}
		return day;
	}
	//��������
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
		while (_day >= Getday(_year, _month))
		{
			_day -= Getday(_year, _month);
			++_month;	
			if (_month == 13)
			{
				++_year;
				_month = 1;
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
		while (_day <= 0)
		{
			--_month;
			if (_month <= 0)
			{
				--_year;
				_month = 12;
			}
			_day += Getday(_year, _month);
		}
		return *this;
	}

	Date operator+(int day)
	{
		//�ӷ������Ƿ�����ӻ������Ľ�������Բ�����this��ֱ�ӼӼ��������ı�this�е�ֵ��
		//���Թ���һ����ʱ���������ء�
		Date ret(*this);
		ret += day;
		return ret;
	}

	//d - day
	Date operator-(int day)
	{
		Date ret(*this);	//*this ---> d
		ret -= day;			//ret.operator-=(&ret, day)
		return ret;
	}

	//d1 - d2
	int operator-(const Date& d)
	{
		Date d1(*this);
		Date d2(d);
		int day = 0;
		int flag = 1;
		if (d1 < d2)
		{
			d1 = d2;
			d2 = *this;
			flag = -1;
		}
		while (d2 < d1)
		{
			++d2;
			++day;
		}
		return day * flag;
	}

	//++date
	Date& operator++()
	{
		return *this += 1;
	}
	//date++
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
		return !((*this < d) && (*this == d));
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
	Date d1(2018, 5, 5);
	Date d2(2019, 3, 14);
	cout << "d1(2018, 5, 5) += 60: " << endl;
	d1 += 60;
	cout << d1 << endl;
	cout << "d2(2019, 3, 14) -= 364" << endl;
	d2 -= 364;
	cout << d2 << endl;

	cout << "d1(2018, 5, 5) += 60  -  d2(2019, 3, 14) -= 364" << endl;
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
#endif