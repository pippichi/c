#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("*************************\n");
	printf("*** 1. play  0. exit ****\n");
	printf("*************************\n");
}

void init(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void display(char board[ROW][COL], int row, int col){
	for (int i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			if (j < col - 1) printf(" %c |", board[i][j]);
			else printf(" %c \n", board[i][j]);
		}
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				if (j < col - 1) printf("---|");
				else printf("---\n");
			}
		}
	}
}

int is_valid(int x, int y, int row, int col) {
	if (x < 1 || x > row || y < 1 || y > col) {
		printf("坐标不合法!\n");
		return 0;
	}
	return 1;
}

void player_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("轮到你走了!\n");
	while (1) {
		printf("输入坐标：\n");
		scanf("%d,%d", &x, &y);
		if (is_valid(x, y, row, col)) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("该坐标被占用！\n");
			}
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑走！\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '&';
			break;
		}
	}
}

int isFull(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ') return 0;
		}
	}
	return 1;
}

char judge(char board[ROW][COL], int row, int col) {
	char temp = 0;
	int x = 0;
	int y = 0;
	for (x = 0; x < row - 4; x++) {
		for (y = 0; y < col - 4; y++) {
			if (board[x][y] != ' ' && board[x][y + 1] == board[x][y] && board[x][y] == board[x][y + 2] && board[x][y] == board[x][y + 3] && board[x][y] == board[x][y + 4]) return board[x][y];
			if (board[x][y] != ' ' && board[x+1][y] == board[x][y] && board[x][y] == board[x + 2][y] && board[x][y] == board[x + 3][y] && board[x][y] == board[x + 4][y]) return board[x][y];
			if (board[x][y] != ' ' && board[x + 1][y + 1] == board[x][y] && board[x][y] == board[x + 2][y + 2] && board[x][y] == board[x + 3][y + 3] && board[x][y] == board[x + 4][y + 4]) return board[x][y];
		}
	}
	for (x = 0; x < row - 4; x++) {
		for (y = 4; y < col; y++) {
			if (board[x][y] != ' ' && board[x + 1][y - 1] == board[x][y] && board[x][y] == board[x + 2][y - 2] && board[x][y] == board[x + 3][y - 3] && board[x][y] == board[x + 4][y - 4]) return board[x][y];
		}
	}
	if (isFull(board, row, col)) return 'F';
	return 'C';
}
