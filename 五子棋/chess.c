#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game() {
	char board[ROW][COL] = { 0 };
	init(board, ROW, COL);
	display(board, ROW, COL);
	char res = 0;
	while (1) {
		player_move(board, ROW, COL);
		display(board, ROW, COL);
		res = judge(board, ROW, COL);
		if(res != 'C') {
			break;
		}
		computer_move(board, ROW, COL);
		display(board, ROW, COL);
		res = judge(board, ROW, COL);
		if (res != 'C') {
			break;
		}
	}
	if (res == '*') {
		printf("你赢了！\n");
	}
	else if (res == '&') {
		printf("电脑赢!\n");
	}
	else if (res == 'F') {
		printf("平局！\n");
	}
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入：");
		scanf("%d", &input);

		switch (input) {
		case 0:
			printf("游戏结束！\n");
			break;
		case 1:
			printf("开始游戏！\n");
			game();
			break;
		default:
			printf("输入错误！\n");
			break;
		}
	} while (input);
	return 0;
}
