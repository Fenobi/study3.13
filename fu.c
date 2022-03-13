#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("***************************************\n");
	printf("***************  1.开始   *************\n");
	printf("***************  0.结束   *************\n");
	printf("***************************************\n");
}

void menu1()
{
	printf("***************************************\n");
	printf("***************  1.简单   *************\n");
	printf("***************  2.困难   *************\n");
	printf("***************************************\n");
}

void game(int c)
{
	char board[ROW][COL];

	//初始化棋盘
	Initboard(board, ROW, COL);
	system("cls");

	//打印棋盘
	DisplayBoard(board, ROW, COL,c);

	char x = 0;//接收游戏状态
	while (1)
	{
		printf("       *_*      注意      *_*\n");
		printf("       由于技术原因，在输入坐标时请输入数字\n       ^_^\n");
		printf("**************************************************\n**************************************************\n");
		//玩家输入
		PlayerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL,c);

		//判断玩家胜利
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}
		Sleep(500);
		//电脑输入
		switch (c)
		{
		case 1:
		{
			
			ComputerMove1(board, ROW, COL);
			break;
		}
		case 2:
		{
			
			ComputerMove(board, ROW, COL);
			break;
		}
		}
		system("cls");
		DisplayBoard(board, ROW, COL,c);

		//判断电脑胜利
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}
	}
	//判断其他状态
	if (x == '*')
	{
		printf("游戏结束，玩家获胜\n");

	}
	else if (x == '#')
	{
		printf("游戏结束，电脑获胜\n");
	}
	else
	{
		printf("游戏结束，平局\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	int j = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			menu1();
			printf("请选择难度：>");
			scanf("%d", &j);
			game(j);
			break;
		}
		/*case 2:
		{
			menu1();
			printf("请选择难度：>");
			scanf("%d", &j);
			game(j);
			break;
		}*/
		case 0:
		{
			printf("退出\n");
			break;
		}
		default:
		{
			printf("选择错误，请重新选择\n");
			break;
		}
		}
	} while (n);
	return 0;
}