#define _crt_secure_no_warnings 1
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "2048.h"
using namespace std;
int main()
{
	int choice;
	srand((unsigned int)time(NULL));
	//bug1:������ĸ��ֱ���˳������쳣
	do {
		show();
		cout << "������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "��Ϸ��ʼ������" << endl;
			game();
			break;
		case 2:
			openReadFile();
			break;
		case 3:
			cout << "��Ϸ�˳��ɹ��������ڻ�����Դ...��" << endl;
			Sleep(500);
			exit(0);
		default:
			cout << "�����������������룡����" << endl;
			break;
		}
	} while (choice);
	system("pause");
	return 0;
}


