#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game() {
	char set[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init(set, ROWS, COLS, '0');
	init(show, ROWS, COLS, '*');
	set_mine(set, ROW, COL);
	display(set, ROW, COL);
	display(show, ROW, COL);
	play(set, show, ROW, COL);
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
