#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define ROW 3
#define COL 3

//��ʼ������
void Initboard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col,int n);

void PlayerMove(char board[ROW][COL], int row, int col);
//����ģʽ
void ComputerMove(char board[ROW][COL], int row, int col);
//��ģʽ
void ComputerMove1(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);
//�ж���Ӯ
//��һ�ʤ���*
//���Ի�ʤ���#
//ƽ�����P
//��Ϸ�����������J


