#ifndef __GAME_H__
#define __GAME_H__
#define SIZE 10
#define ROW SIZE
#define COL SIZE
#define ROWS ROW+2
#define COLS COL+2
#define MINE_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void menu();
void init(char board[ROWS][COLS], int row, int col, char type);
void display(char board[ROWS][COLS], int row, int col);
void set_mine(char board[ROWS][COLS], int row, int col);
void play(char set[ROWS][COLS], char show[ROWS][COLS], int row, int col);

#endif
