#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
#include "2048.h"
using namespace std;

//��ӡ��Ϸ����
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
	//����������ֵ�����
	x = rand() % 4;
	y = rand() % 4;
	//�Ѿ������ֵĵط������ٴ�������
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
	//�����������,��Ϸ����������
	if (count >= ROW * COL){
		cout << "�������ˣ���Ϸ����" << endl;
		return true;
	}
	//�������û������Ϸ����
	if (count < ROW * COL){
		return false;
	}
}

bool isWin(int board[ROW][COL]){
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (board[i][j] == 2048){
				cout << "��Ϸʤ��������" << endl;
				return true;
			}
		}
	}
	return false;
}

//��ȡ�����������������һ��
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
		cout << "��������������w(��)/a(��)/s(��)/d(��)" << endl;
	}
}

void up(int board[ROW][COL])
{
	//��һ�в���
	for (int row = 1; row < ROW; row++){
		//ÿһ�б���һ��
		for (int rrow = row; rrow >= 1; rrow--){
			//���е�ÿһ��Ԫ�ض�Ҫ���бȽ�
			for (int col = 0; col < COL; col++){
				//�������Ԫ��Ϊ0�����������ݽ��а���
				if (board[rrow - 1][col] == 0){
					board[rrow - 1][col] = board[rrow][col];
					board[rrow][col] = 0;
				}
				else{
					//�������Ԫ�ز�Ϊ0���뱾��Ԫ����ͬ��������Ԫ�ط���
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
	//�����һ�����ݲ���
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
				//��һ������Ϊ��
				if (board[row][ccol - 1] == 0)
				{
					board[row][ccol - 1] = board[row][ccol];
					board[row][ccol] = 0;
				}
				else
				{
					//�ϲ�
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
				//��һ������Ϊ��
				if (board[row][ccol + 1] == 0)
				{
					board[row][ccol + 1] = board[row][ccol];
					board[row][ccol] = 0;
				}
				else
				{
					//�ϲ�
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
		cout << "������w(��)/a(��)/s(��)/d(��)" << endl;
		direction = Input();
		switch (direction)
		{
		case 1:
			//��
			up(board);
			Print(board);
			break;
		case 2:
			//��
			down(board);
			Print(board);
			break;
		case 3:
			//��
			left(board);
			Print(board);
			break;
		case 4:
			//��
			right(board);
			Print(board);
			break;
		default:
			cout << "��������" << endl;
			break;
		}

	} while (isOver(board) == false && isWin(board) == false);
}


//�Ķ������ֲ�
void openReadFile()
{
	ifstream in("help.txt");
	for (string str; getline(in, str);)
		cout << str << endl;
	in.close();
}

//ʵ�ֽ���
void show(){
	cout << "*************************************************" << endl;
	cout << "              ��ӭ����2048С��Ϸ                  " << endl;
	cout << "              1����ʼ��Ϸ                        " << endl;
	cout << "              2������                            " << endl;
	cout << "              3���˳�                            " << endl;
	cout << "*************************************************" << endl;
	cout << "             �����ˣ�Mark��                       " << endl;
	cout << "             ����������PIGlv                      " << endl;
}


