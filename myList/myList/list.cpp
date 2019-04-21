#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "list.h"
using namespace std;

//�����ӡ����
template<class T>
void PrintList(myList::List<T>& l)
{
	auto lit = l.begin();
	while (lit != l.end()){
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
}

//�����ӡ����
template<class T>
void PrintListReverse(const myList::List<T>& l)
{
	auto it = l.crbegin();
	while (it != l.crend()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//����List�Ĺ���
void Test1()
{
	//myList::List<int> l1;
	//l1.PushBack(1);
	//l1.PushBack(2);
	//l1.PushBack(3);
	//l1.PushBack(4);
	//myList::List<int> l2;
	//l2 = l1;
	//PrintList(l1);
	//PrintList(l2);
	myList::List<int> l1;
	myList::List<int> l2(10, 5);
	PrintList(l2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	myList::List<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);

	myList::List<int> l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
	PrintListReverse(l1);
	
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	myList::List<char> l5(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(l5);
}

//����PushBack()/PopBack()/PushFront()/PopFront()
void Test2()
{
	//PushBack()/PushFront()
	myList::List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	PrintList(l);

	l.PopBack();
	l.PopBack();
	PrintList(l);

	l.PopBack();
	cout << l.Size() << endl;
	//PushFront()/PopFront()
	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	PrintList(l);

	l.PopFront();
	l.PopFront();
	PrintList(l);

	l.PopFront();
	cout << l.Size() << endl;
}

//Insert()/Erase()
void Test3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	myList::List<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto pos = l.begin();
	l.Insert(pos, 0);
	PrintList(l);

	++pos;
	l.Insert(pos, 7);
	PrintList(l);

	l.Erase(l.begin());
	auto pos2 = l.Erase(pos);
	PrintList(l);
	
	//posָ��Ľ���Ѿ���ɾ����pos������ʧЧ
	cout << *pos << endl;
	cout << *pos2 << endl;

	auto it = l.begin();
	while (it != l.end()){
		it = l.Erase(it);
	}
	cout << l.Size() << endl;
}

//ReSize()/Clear()
void Test4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	myList::List<int> l(array, array + sizeof(array) / sizeof(array[0]));
	cout << l.Size() << endl;
	PrintList(l);

	l.ReSize(10, 7);
	cout << l.Size() << endl;
	PrintList(l);

	l.ReSize(4);
	cout << l.Size() << endl;
	PrintList(l);

	l.ReSize(3, 0);
	cout << l.Size() << endl;
	PrintList(l);

	l.Clear();
	cout << l.Size() << endl;
	PrintList(l);
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	system("pause");
	return 0;
}