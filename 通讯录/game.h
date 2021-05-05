#pragma once
#ifndef __GAME_H__
#define __GAME_H__
// 使用动态内存分配改进代码之后将下面的代码注释
// #define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
// 使用动态内存分配改进代码之后增加下面的代码
#define DEFAULT_SZ 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	// 使用文件操作改进代码之后增加下面的代码
	SAVE
};
struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

// 通讯录类型
struct Contact {
	// 使用动态内存分配改进代码之后将下面的代码注释
	// struct PeoInfo data[MAX];
	struct PeoInfo* data;
	int size; // 记录当前已经有的元素的个数
	// 使用动态内存分配改进代码之后增加下面的代码
	int capacity; // 当前通讯录的最大容量，目的是用于判断什么时候该调整data数组的大小
};

//// 声明函数
// 初始化通讯录的函数
void InitContact(struct Contact* ps);
// 添加一个信息到通讯录
void AddContact(struct Contact* ps);
// 打印通讯录中的信息
void ShowContact(const struct Contact* ps);
// 删除指定的联系人
void DelContact(struct Contact* ps);
// 查找指定的人的信息
void SearchContact(const struct Contact* ps);
// 修改指定的人的信息
void ModifyContact(struct Contact* ps);
// 排序通讯录内容
void SortContact(struct Contact* ps);
// 使用动态内存分配改进代码之后增加下面的代码
// 释放动态开辟的内存
void DestroyContact(struct Contact* ps);
// 使用文件操作改进代码之后增加下面的代码
// 保存文件
void SaveContact(struct Contact* ps);
// 使用文件操作改进代码之后增加下面的代码
// 加载文件中的信息到通讯录
void LoadContact(struct Contact* ps);
#endif
