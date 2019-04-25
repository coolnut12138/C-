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
	//bug1:输入字母会直接退出或者异常
	do {
		show();
		cout << "请输入选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "游戏开始！！！" << endl;
			game();
			break;
		case 2:
			openReadFile();
			break;
		case 3:
			cout << "游戏退出成功！（正在回收资源...）" << endl;
			Sleep(500);
			exit(0);
		default:
			cout << "输入有误，请重新输入！！！" << endl;
			break;
		}
	} while (choice);
	system("pause");
	return 0;
}


