#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu() {
	printf("************************************************\n");
	printf("********* 1.add           2.del    ************\n");
	printf("********* 3.search        4.modify ************\n");
	printf("********* 5.show          6.sort   *************\n");
	printf("********* 7.save          0.exit   *************\n");
	printf("************************************************\n");
}

int main() {
	int input = 0;
	// 创建通讯录
	// 使用动态内存分配改进代码之后将下面的代码注释
	// struct Contact con; // con就是通讯录，里面包含：一个能容纳1000个PeoInfo的数组和用于记录当前已有PeoInfo元素个数的size
	// 使用动态内存分配改进代码之后增加下面的代码
	struct Contact con; // con就是通讯录，里面包含：data指针和用于记录当前已有PeoInfo元素个数的size和data指向数组的容量capacity
	// 初始化通讯录
	InitContact(&con);
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			// 使用文件操作改进代码之后增加下面的代码
			SaveContact(&con);
			// 使用动态内存分配改进代码之后增加下面的代码
			// 初始化的时候动态开辟了内存，那么这个时候就要释放这些动态开辟的内存
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
			// 使用文件操作改进代码之后增加下面的代码
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}