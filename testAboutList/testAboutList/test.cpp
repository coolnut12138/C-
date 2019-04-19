#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//list 的构造
void Test1()
{
	list<int> l1;	//空l1
	list<int> l2(4, 100);	//l2中放4个值为100的元素
	list<int> l3(l2.begin(), l2.end());	//用l2的[begin(), end()) 左闭右开的区间构造l3
	list<int> l4(l3);	//用l3拷贝构造l4
	//以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));
	//用迭代器方式打印l5中的元素
	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	for (auto& e : l5){
		cout << e << " ";
	}
	cout << endl;
}

//list iterator的使用
void Test2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	//使用正向迭代器正向打印list的元素
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//使用反向迭代器逆序打印list中的元素
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//const 的正向迭代器
	auto cit = l.cbegin();
	cout << typeid(cit).name() << endl;
	//*cit = 10;
}

//list capacity
void Test3()
{
	//int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	list<int> l;
	//打印list中有效结点的个数
	cout << l.size() << endl;

	//检测list是否为空
	if (l.empty()){
		cout << "空的list" << endl;
	}
	else{
		for (const auto& e : l){
			cout << e << " ";
		}
		cout << endl;
	}
}

//list element access
void Test4()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));

	for (auto& e : l1){
		cout << e << " ";
	}
	cout << endl;

	//将list中的第一个结点和最后一个结点的值改为10
	l1.front() = 10;
	l1.back() = 10;
	for (auto& e : l1){
		cout << e << " ";
	}
	cout << endl;

	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	//int& a = l2.front
	const int& ca = l2.front();
	cout << ca << endl;
}

//list modifiers
void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}

//push_back/pop_back/push_front/pop_front
void TestList1()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	//在list尾部插入4，头部插入0
	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	//删除list尾结点和头结点
	L.pop_back();
	L.pop_front();
	PrintList(L);
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestList2()
{
	//push_back尾插：先构造好元素，然后将元素拷贝到结点中，插入时先调构造函数，再调拷贝构造
	//emplace_back尾插：先构造结点，然后调用构造函数在结点中直接构造对象
	//emplace_back比push_back更高效，少了一步拷贝构造函数的调用
	list<Date> l;
	Date d(2018, 10, 20);
	l.push_back(d);
	l.emplace_back(2018, 10, 21);
	l.emplace_front(2018, 10, 19);
}

//insert/erase
void TestList3()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	//获取链表中第二个结点
	auto pos = ++L.begin();
	cout << *pos << endl;

	//在pos前插入值为4的元素
	L.insert(pos, 4);
	PrintList(L);

	//在pos前插入5个值为5的元素
	L.insert(pos, 5, 5);
	PrintList(L);

	//在pos前插入[v.begin(), v.end())区间的元素
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);
}

//迭代器失效
void TestListIterator1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	auto it = l.begin();
	//while (it != l.end())
	//{
	//	//erase()函数执行后，it所指向的结点已经被删除，因此it失效，在下一次使用it时，必须先给it赋值
	//	l.erase(it);
	//	++it;
	//}
	while (it != l.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//更正
	it = l.begin();
	while (it != l.end())
	{
		l.erase(it++);
	}

	it = l.begin();
	while (it != l.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//TestList1();
	//TestList2();
	//TestList3();
	TestListIterator1();
	system("pause");
	return 0;
}