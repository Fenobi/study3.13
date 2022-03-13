#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define ROW 3
#define COL 3

//初始化函数
void Initboard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col,int n);

void PlayerMove(char board[ROW][COL], int row, int col);
//困难模式
void ComputerMove(char board[ROW][COL], int row, int col);
//简单模式
void ComputerMove1(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);
//判断输赢
//玩家获胜输出*
//电脑获胜输出#
//平局输出P
//游戏继续进行输出J


