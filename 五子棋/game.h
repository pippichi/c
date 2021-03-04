#ifndef __GAME_H__
#define __GAME_H__
#define SIZE 3
#define ROW SIZE
#define COL SIZE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void menu();
void init(char board[ROW][COL], int row, int col);
void display(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
char judge(char board[ROW][COL], int row, int col);

#endif
