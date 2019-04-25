#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <time.h>

#define ROW 4
#define COL 4
#define w 1


//游戏界面
void Print(int board[ROW][COL]);
void openReadFile();
void game();
void createNum(int board[ROW][COL]);
bool isOver(int board[ROW][COL]);
bool isWin(int board[ROW][COL]);
int Input();
void up(int board[ROW][COL]);
void down(int board[ROW][COL]);
void left(int board[ROW][COL]);
void right(int board[ROW][COL]);
//登陆界面
void show();