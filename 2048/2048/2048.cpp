#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
#include "2048.h"
using namespace std;

//打印游戏界面
void Print(int board[ROW][COL])
{
	for (int i = 0; i < ROW; i++){
		cout << "---------------------------------" << endl;
		for (int j = 0; j < COL; j++){
			if (board[i][j] == 0){
				cout << "|\t";
			}
			else{
				cout << "|" << board[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "---------------------------------" << endl;
}

void createNum(int board[ROW][COL]){
	int x = -1;
	int y = -1;
	//随机出现数字的坐标
	x = rand() % 4;
	y = rand() % 4;
	//已经有数字的地方不能再创造数字
	while (x < ROW || y << COL){
		if (board[x][y] == 0){
			board[x][y] = 2;
			break;
		}
		else{
			x = rand() % 4;
			y = rand() % 4;
		}
	}
}

bool isOver(int board[ROW][COL]){
	int count = 0;
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (board[i][j] != 0 && board[i][j] != 2048){
				++count;
			}
		}
	}
	//如果棋盘满了,游戏结束，输了
	if (count >= ROW * COL){
		cout << "棋盘满了，游戏结束" << endl;
		return true;
	}
	//如果棋盘没满，游戏继续
	if (count < ROW * COL){
		return false;
	}
}

bool isWin(int board[ROW][COL]){
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (board[i][j] == 2048){
				cout << "游戏胜利！！！" << endl;
				return true;
			}
		}
	}
	return false;
}

//读取输入的是上下左右哪一个
int Input()
{
	int direction = -1;
	char input;
	cin >> input;
	switch (input)
	{
	case 'w':
		return 1;
		break;
	case 's':
		return 2;
		break;
	case 'a':
		return 3;
		break;
	case 'd':
		return 4;
		break;
	default:
		cout << "输入有误，请输入w(上)/a(左)/s(下)/d(右)" << endl;
	}
}

void up(int board[ROW][COL])
{
	//第一行不动
	for (int row = 1; row < ROW; row++){
		//每一行遍历一次
		for (int rrow = row; rrow >= 1; rrow--){
			//此行的每一列元素都要进行比较
			for (int col = 0; col < COL; col++){
				//如果上行元素为0，将本行数据进行搬移
				if (board[rrow - 1][col] == 0){
					board[rrow - 1][col] = board[rrow][col];
					board[rrow][col] = 0;
				}
				else{
					//如果上行元素不为0且与本行元素相同，则上行元素翻倍
					if (board[rrow - 1][col] == board[rrow][col]){
						board[rrow - 1][col] *= 2;
						board[rrow][col] = 0;
					}
				}
			}
		}
	}
}

void down(int board[ROW][COL])
{
	//最地下一行数据不动
	for (int row = ROW - 2; row >= 0; row--){
		for (int rrow = row; rrow < ROW - 1; rrow++){
			for (int col = 0; col < COL; col++){
				if (board[rrow + 1][col] == 0){
					board[rrow + 1][col] = board[rrow][col];
					board[rrow][col] = 0;
				}
				else{
					if (board[rrow + 1][col] == board[rrow][col]){
						board[rrow + 1][col] *= 2;
						board[rrow][col] = 0;
					}
				}
			}
		}
	}
}
void left(int board[ROW][COL])
{
	for (int col = 1; col < COL; ++col)
	{
		for (int ccol = col; ccol >= 1; --ccol)
		{
			for (int row = 0; row < ROW; ++row)
			{
				//上一个格子为空
				if (board[row][ccol - 1] == 0)
				{
					board[row][ccol - 1] = board[row][ccol];
					board[row][ccol] = 0;
				}
				else
				{
					//合并
					if (board[row][ccol - 1] == board[row][ccol])
					{
						board[row][ccol - 1] *= 2;
						board[row][ccol] = 0;
					}

				}
			}
		}
	}
}
void right(int board[ROW][COL])
{
	for (int col = COL - 2; col >= 0; --col)
	{
		for (int ccol = col; ccol <= COL - 2; ++ccol)
		{
			for (int row = 0; row < ROW; ++row)
			{
				//上一个格子为空
				if (board[row][ccol + 1] == 0)
				{
					board[row][ccol + 1] = board[row][ccol];
					board[row][ccol] = 0;
				}
				else
				{
					//合并
					if (board[row][ccol + 1] == board[row][ccol])
					{
						board[row][ccol + 1] *= 2;
						board[row][ccol] = 0;
					}

				}
			}
		}
	}
}

void game()
{
	int direction = -1;
	int board[ROW][COL] = { 0 };
	createNum(board);
	Print(board);
	do
	{
		createNum(board);
		cout << "请输入w(上)/a(左)/s(下)/d(右)" << endl;
		direction = Input();
		switch (direction)
		{
		case 1:
			//上
			up(board);
			Print(board);
			break;
		case 2:
			//下
			down(board);
			Print(board);
			break;
		case 3:
			//左
			left(board);
			Print(board);
			break;
		case 4:
			//右
			right(board);
			Print(board);
			break;
		default:
			cout << "输入有误" << endl;
			break;
		}

	} while (isOver(board) == false && isWin(board) == false);
}


//阅读帮助手册
void openReadFile()
{
	ifstream in("help.txt");
	for (string str; getline(in, str);)
		cout << str << endl;
	in.close();
}

//实现界面
void show(){
	cout << "*************************************************" << endl;
	cout << "              欢迎来到2048小游戏                  " << endl;
	cout << "              1、开始游戏                        " << endl;
	cout << "              2、帮助                            " << endl;
	cout << "              3、退出                            " << endl;
	cout << "*************************************************" << endl;
	cout << "             制作人：Mark王                       " << endl;
	cout << "             感情赞助：PIGlv                      " << endl;
}


