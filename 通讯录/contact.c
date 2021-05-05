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
	// ����ͨѶ¼
	// ʹ�ö�̬�ڴ����Ľ�����֮������Ĵ���ע��
	// struct Contact con; // con����ͨѶ¼�����������һ��������1000��PeoInfo����������ڼ�¼��ǰ����PeoInfoԪ�ظ�����size
	// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
	struct Contact con; // con����ͨѶ¼�����������dataָ������ڼ�¼��ǰ����PeoInfoԪ�ظ�����size��dataָ�����������capacity
	// ��ʼ��ͨѶ¼
	InitContact(&con);
	do {
		menu();
		printf("��ѡ��>");
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
			// ʹ���ļ������Ľ�����֮����������Ĵ���
			SaveContact(&con);
			// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
			// ��ʼ����ʱ��̬�������ڴ棬��ô���ʱ���Ҫ�ͷ���Щ��̬���ٵ��ڴ�
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
			// ʹ���ļ������Ľ�����֮����������Ĵ���
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}