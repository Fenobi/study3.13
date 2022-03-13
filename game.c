#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col,int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			int n = 0;
			for (n = 0; n < col; n++)
			{
				printf("---");
				if (n < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	switch (n)
	{
	case 1:
	{
		printf("简单模式\n");
		break;
	}
	case 2:
	{
		printf("困难模式\n");
		break;
	}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家走>\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("请输入坐标>:");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x <= row && x >= 1 && y >= 1 && y <= col)
		{
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入>:");
			}
		}
		else
		{
			printf("坐标非法，请重新输入<:");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走:\n");
	//判断第一行
	if (board[0][0] == ' ' && board[0][1] == '*' && board[0][2] == '*'|| board[0][0] == ' ' && board[0][1] == '#' && board[0][2] == '#')
	{
		board[0][0] = '#';
	}
	else if (board[0][0] == '*' && board[0][1] == ' ' && board[0][2] == '*'|| board[0][0] == '#' && board[0][1] == ' ' && board[0][2] == '#')
	{
		board[0][1] = '#';
	}
	else if (board[0][0] == '*' && board[0][1] == '*' && board[0][2] == ' '|| board[0][0] == '#' && board[0][1] == '#' && board[0][2] == ' ')
	{
		board[0][2] = '#';
	}
	//判断第二行
	else if (board[1][0] == ' ' && board[1][1] == '*' && board[1][2] == '*'|| board[1][0] == ' ' && board[1][1] == '#' && board[1][2] == '#')
	{
		board[0][0] = '#';
	}
	else if (board[1][0] == '*' && board[1][1] == ' ' && board[1][2] == '*'|| board[1][0] == '#' && board[1][1] == ' ' && board[1][2] == '#')
	{
		board[0][1] = '#';
	}
	else if (board[1][0] == '*' && board[1][1] == '*' && board[1][2] == ' '|| board[1][0] == '#' && board[1][1] == '#' && board[1][2] == ' ')
	{
		board[1][2] = '#';
	}
	//判断第三行
	else if (board[2][0] == ' ' && board[2][1] == '*' && board[2][2] == '*'|| board[2][0] == ' ' && board[2][1] == '#' && board[2][2] == '#')
	{
		board[2][0] = '#';
	}
	else if (board[2][0] == '*' && board[2][1] == ' ' && board[2][2] == '*'|| board[2][0] == '#' && board[2][1] == ' ' && board[2][2] == '#')
	{
		board[2][1] = '#';
	}
	else if (board[2][0] == '*' && board[2][1] == '*' && board[2][2] == ' '|| board[2][0] == '#' && board[2][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
	}
	//判断第一列
	else if (board[0][0] == ' ' && board[1][0] == '*' && board[2][0] == '*'|| board[0][0] == ' ' && board[1][0] == '#' && board[2][0] == '#')
	{
		board[0][0] = '#';
	}
	else if (board[0][0] == '*' && board[1][0] == ' ' && board[2][0] == '*'|| board[0][0] == '#' && board[1][0] == ' ' && board[2][0] == '#')
	{
		board[1][0] = '#';
	}
	else if (board[0][0] == '*' && board[1][0] == '*' && board[2][0] == ' '|| board[0][0] == '#' && board[1][0] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
	}
	//判断第二列
	else if (board[0][1] == ' ' && board[1][1] == '*' && board[2][1] == '*'|| board[0][1] == ' ' && board[1][1] == '#' && board[2][1] == '#')
	{
		board[0][1] = '#';
	}
	else if (board[0][1] == '*' && board[1][1] == ' ' && board[2][1] == '*'|| board[0][1] == '#' && board[1][1] == ' ' && board[2][1] == '#')
	{
		board[1][1] = '#';
	}
	else if (board[0][1] == '*' && board[1][1] == '*' && board[2][1] == ' '|| board[0][1] == '#' && board[1][1] == '#' && board[2][1] == ' ')
	{
		board[2][1] = '#';
	}
	//判断第三列
	else if (board[0][1] == ' ' && board[1][2] == '*' && board[2][2] == '*'|| board[0][1] == ' ' && board[1][2] == '#' && board[2][2] == '#')
	{
		board[0][1] = '#';
	}
	else if (board[0][1] == '*' && board[1][2] == ' ' && board[2][2] == '*'|| board[0][1] == '#' && board[1][2] == ' ' && board[2][2] == '#')
	{
		board[1][2] = '#';
	}
	else if (board[0][1] == '*' && board[1][2] == '*' && board[2][2] == ' '|| board[0][1] == '#' && board[1][2] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
	}
	//判断左对角线
	else if (board[0][0] == ' ' && board[1][1] == '*' && board[2][2] == '*'|| board[0][0] == ' ' && board[1][1] == '#' && board[2][2] == '#')
	{
		board[0][0] = '#';
	}
	else if (board[0][0] == '*' && board[1][1] == ' ' && board[2][2] == '*'|| board[0][0] == '#' && board[1][1] == ' ' && board[2][2] == '#')
	{
		board[1][1] = '#';
	}
	else if (board[0][0] == '*' && board[1][1] == '*' && board[2][2] == ' '|| board[0][0] == '#' && board[1][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
	}
	//判断右对角线
	else if (board[0][2] == ' ' && board[1][1] == '*' && board[2][0] == '*'|| board[0][2] == ' ' && board[1][1] == '#' && board[2][0] == '#')
	{
		board[0][2] = '#';
	}
	else if (board[0][2] == '*' && board[1][1] == ' ' && board[2][0] == '*'|| board[0][2] == '#' && board[1][1] == ' ' && board[2][0] == '#')
	{
		board[1][1] = '#';
	}
	else if (board[0][2] == '*' && board[1][1] == '*' && board[2][0] == ' '|| board[0][2] == '#' && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
	}
	else if (board[1][1] != '*'&&board[1][1]!='#')
	{
		board[1][1] = '#';
	}
	else
	{
		while (1)
		{
			int x = 0;
			int y = 0;
			x = rand() % row;
			y = rand() % col;
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
		}
	}
}

void ComputerMove1(char board[ROW][COL], int row, int col)
{
	printf("电脑走:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}



char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断斜线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'P';
	}
	return 'J';

}
