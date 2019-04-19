#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//list �Ĺ���
void Test1()
{
	list<int> l1;	//��l1
	list<int> l2(4, 100);	//l2�з�4��ֵΪ100��Ԫ��
	list<int> l3(l2.begin(), l2.end());	//��l2��[begin(), end()) ����ҿ������乹��l3
	list<int> l4(l3);	//��l3��������l4
	//������Ϊ���������乹��l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));
	//�õ�������ʽ��ӡl5�е�Ԫ��
	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	for (auto& e : l5){
		cout << e << " ";
	}
	cout << endl;
}

//list iterator��ʹ��
void Test2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	//ʹ����������������ӡlist��Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//const �����������
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
	//��ӡlist����Ч���ĸ���
	cout << l.size() << endl;

	//���list�Ƿ�Ϊ��
	if (l.empty()){
		cout << "�յ�list" << endl;
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

	//��list�еĵ�һ���������һ������ֵ��Ϊ10
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

	//��listβ������4��ͷ������0
	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	//ɾ��listβ����ͷ���
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
	//push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ���������У�����ʱ�ȵ����캯�����ٵ���������
	//emplace_backβ�壺�ȹ����㣬Ȼ����ù��캯���ڽ����ֱ�ӹ������
	//emplace_back��push_back����Ч������һ���������캯���ĵ���
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

	//��ȡ�����еڶ������
	auto pos = ++L.begin();
	cout << *pos << endl;

	//��posǰ����ֵΪ4��Ԫ��
	L.insert(pos, 4);
	PrintList(L);

	//��posǰ����5��ֵΪ5��Ԫ��
	L.insert(pos, 5, 5);
	PrintList(L);

	//��posǰ����[v.begin(), v.end())�����Ԫ��
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);
}

//������ʧЧ
void TestListIterator1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	auto it = l.begin();
	//while (it != l.end())
	//{
	//	//erase()����ִ�к�it��ָ��Ľ���Ѿ���ɾ�������itʧЧ������һ��ʹ��itʱ�������ȸ�it��ֵ
	//	l.erase(it);
	//	++it;
	//}
	while (it != l.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//����
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