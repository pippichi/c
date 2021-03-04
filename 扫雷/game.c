#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("*************************\n");
	printf("*** 1. play  0. exit ****\n");
	printf("*************************\n");
}

void init(char board[ROWS][COLS], int row, int col, char type) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = type;
		}
	}
}

void display(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	for (i = 0; i <= col; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%2d ", i);
		for (int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char board[ROWS][COLS], int row, int col) {
	int count = MINE_COUNT;
	int x = 0;
	int y = 0;
	while (count) {
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mines(char board[ROWS][COLS], int x, int y) {
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}

void clear(char set[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y) {
	if (x < 1 || x > row || y < 1 || y > col) {
		return;
	}
	if ((set[x - 1][y - 1] == '0' || set[x - 1][y - 1] == '2' || set[x - 1][y - 1] == '3') &&
		(set[x - 1][y] == '0' || set[x - 1][y] == '2' || set[x - 1][y] == '3') &&
		(set[x - 1][y + 1] == '0' || set[x - 1][y + 1] == '2' || set[x - 1][y + 1] == '3') &&
		(set[x][y - 1] == '0' || set[x][y - 1] == '2' || set[x][y - 1] == '3') &&
		(set[x][y + 1] == '0' || set[x][y + 1] == '2' || set[x][y + 1] == '3') &&
		(set[x + 1][y - 1] == '0' || set[x + 1][y - 1] == '2' || set[x + 1][y - 1] == '3') &&
		(set[x + 1][y] == '0' || set[x + 1][y] == '2' || set[x + 1][y] == '3') &&
		(set[x + 1][y + 1] == '0' || set[x + 1][y + 1] == '2' || set[x + 1][y + 1] == '3')) {
		show[x - 1][y - 1] = ' ';
		show[x - 1][y] = ' ';
		show[x - 1][y + 1] = ' ';
		show[x][y - 1] = ' ';
		show[x][y + 1] = ' ';
		show[x + 1][y - 1] = ' ';
		show[x + 1][y] = ' ';
		show[x + 1][y + 1] = ' ';
		if (set[x - 1][y - 1] == '0') set[x - 1][y - 1] = '2';
		else set[x - 1][y - 1] = '3';
		if (set[x - 1][y] == '0') set[x - 1][y] = '2';
		else set[x - 1][y] = '3';
		if (set[x - 1][y + 1] == '0') set[x - 1][y + 1] = '2';
		else set[x - 1][y + 1] = '3';
		if (set[x][y - 1] == '0') set[x][y - 1] = '2';
		else set[x][y - 1] = '3';
		if (set[x][y] == '0') set[x][y] = '2';
		else set[x][y] = '3';
		if (set[x][y + 1] == '0') set[x][y + 1] = '2';
		else set[x][y + 1] = '3';
		if (set[x + 1][y - 1] = '0') set[x + 1][y - 1] = '2';
		else set[x + 1][y - 1] = '3';
		if (set[x + 1][y] == '0') set[x + 1][y] = '2';
		else set[x + 1][y] = '3';
		if (set[x + 1][y + 1] == '0') set[x + 1][y + 1] = '2';
		else set[x + 1][y + 1] = '3';
		if (set[x - 1][y - 1] != '3') {
			clear(set, show, row, col, x - 1, y - 1);
		}
		if (set[x - 1][y + 1] != '3') {
			clear(set, show, row, col, x - 1, y + 1);
		}
		if (set[x + 1][y - 1] != '3') {
			clear(set, show, row, col, x + 1, y - 1);
		}
		if (set[x + 1][y + 1] != '3') {
			clear(set, show, row, col, x + 1, y + 1);
		}
	}
}

void reset(char board[ROWS][COLS], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == '2' || board[i][j] == '3') board[i][j] = '0';
		}
	}
}

int get_star(char set[ROWS][COLS], int row, int col) {
	int res = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (set[i][j] == '*') res++;
		}
	}
	return res;
}

void play(char set[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int star = 0;
	int count = row * col - MINE_COUNT;
	printf("playing...\n");
	while (count) {
		printf("enter x,y:\n");
		scanf("%d,%d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col) {
			printf("invalid x,y\n");
		}
		else {
			if (show[x][y] == '*') {
				if (set[x][y] == '1') {
					display(set, row, col);
					printf("you died\n");
					break;
				}
				else {
					show[x][y] = get_mines(set, x, y) + '0';
					count--;
					if (show[x][y] == '0') {
						clear(set, show, row, col, x, y);
						count = get_star(show, row, col) - MINE_COUNT;
						reset(set, ROWS, COLS);
						printf("还剩%d个安全区\n", count);
					}
					display(show, row, col);
				}
			}
			else {
				printf("already exists\n");
			}
		}
	}
	if (count == 0) {
		printf("you win\n");
		display(set, ROW, COL);
	}
}