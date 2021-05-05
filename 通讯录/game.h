#pragma once
#ifndef __GAME_H__
#define __GAME_H__
// ʹ�ö�̬�ڴ����Ľ�����֮������Ĵ���ע��
// #define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
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
	// ʹ���ļ������Ľ�����֮����������Ĵ���
	SAVE
};
struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

// ͨѶ¼����
struct Contact {
	// ʹ�ö�̬�ڴ����Ľ�����֮������Ĵ���ע��
	// struct PeoInfo data[MAX];
	struct PeoInfo* data;
	int size; // ��¼��ǰ�Ѿ��е�Ԫ�صĸ���
	// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
	int capacity; // ��ǰͨѶ¼�����������Ŀ���������ж�ʲôʱ��õ���data����Ĵ�С
};

//// ��������
// ��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);
// ���һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);
// ��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);
// ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);
// ����ָ�����˵���Ϣ
void SearchContact(const struct Contact* ps);
// �޸�ָ�����˵���Ϣ
void ModifyContact(struct Contact* ps);
// ����ͨѶ¼����
void SortContact(struct Contact* ps);
// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
// �ͷŶ�̬���ٵ��ڴ�
void DestroyContact(struct Contact* ps);
// ʹ���ļ������Ľ�����֮����������Ĵ���
// �����ļ�
void SaveContact(struct Contact* ps);
// ʹ���ļ������Ľ�����֮����������Ĵ���
// �����ļ��е���Ϣ��ͨѶ¼
void LoadContact(struct Contact* ps);
#endif
