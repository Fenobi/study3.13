#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("***************************************\n");
	printf("***************  1.��ʼ   *************\n");
	printf("***************  0.����   *************\n");
	printf("***************************************\n");
}

void menu1()
{
	printf("***************************************\n");
	printf("***************  1.��   *************\n");
	printf("***************  2.����   *************\n");
	printf("***************************************\n");
}

void game(int c)
{
	char board[ROW][COL];

	//��ʼ������
	Initboard(board, ROW, COL);
	system("cls");

	//��ӡ����
	DisplayBoard(board, ROW, COL,c);

	char x = 0;//������Ϸ״̬
	while (1)
	{
		printf("       *_*      ע��      *_*\n");
		printf("       ���ڼ���ԭ������������ʱ����������\n       ^_^\n");
		printf("**************************************************\n**************************************************\n");
		//�������
		PlayerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL,c);

		//�ж����ʤ��
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}
		Sleep(500);
		//��������
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

		//�жϵ���ʤ��
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}
	}
	//�ж�����״̬
	if (x == '*')
	{
		printf("��Ϸ��������һ�ʤ\n");

	}
	else if (x == '#')
	{
		printf("��Ϸ���������Ի�ʤ\n");
	}
	else
	{
		printf("��Ϸ������ƽ��\n");
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
		printf("��ѡ��>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			menu1();
			printf("��ѡ���Ѷȣ�>");
			scanf("%d", &j);
			game(j);
			break;
		}
		/*case 2:
		{
			menu1();
			printf("��ѡ���Ѷȣ�>");
			scanf("%d", &j);
			game(j);
			break;
		}*/
		case 0:
		{
			printf("�˳�\n");
			break;
		}
		default:
		{
			printf("ѡ�����������ѡ��\n");
			break;
		}
		}
	} while (n);
	return 0;
}