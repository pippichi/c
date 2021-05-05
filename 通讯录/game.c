#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

// ʹ���ļ������Ľ�����֮����������Ĵ���
void LoadContact(struct Contact* ps);
void InitContact(struct Contact* ps) {
	// ʹ�ö�̬�ڴ����Ľ�����֮������Ĵ���ע��
	// memset(ps->data, 0, sizeof(ps->data));
	// ps->size = 0;
	// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
	// ����ϣ����ʼ����ʱ��ͨѶ¼�ܷ��������˵���Ϣ
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	// ʹ���ļ������Ľ�����֮����������Ĵ���
	// ���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}

// ʹ���ļ������Ľ�����֮����������Ĵ���
// ��������
static void CheckCapacity(struct Contact* ps);
void LoadContact(struct Contact* ps) {
	struct PeoInfo temp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL) {
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	// ��ȡ�ļ�����ŵ�ͨѶ¼��
	while (fread(&temp, sizeof(struct PeoInfo), 1, pfRead)) {
		CheckCapacity(ps);
		ps->data[ps->size] = temp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
static void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		// ����
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ���\n");
		}
		else {
			printf("����ʧ�ܣ�\n");
		}
	}
}

void AddContact(struct Contact* ps) {
	// ʹ�ö�̬�ڴ����Ľ�����֮������Ĵ���ע��
	// if (ps->size == MAX) {
	// 	 printf("ͨѶ¼�������޷���ӣ�\n");
	// }
	// else {
	// 	printf("���������֣�>");
	// 	scanf("%s", ps->data[ps->size].name);
	// 	printf("���������䣺>");
	// 	scanf("%d", &(ps->data[ps->size].age));
	// 	printf("�������Ա�>");
	// 	scanf("%s", ps->data[ps->size].sex);
	// 	printf("������绰��>");
	// 	scanf("%s", ps->data[ps->size].tele);
	// 	printf("�������ַ��>");
	// 	scanf("%s", ps->data[ps->size].addr);
	// 	ps->size++;
	// 	printf("��ӳɹ���\n");
	// }

	// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
	// ��⵱ǰͨѶ¼������
	// 1.������ˣ������ӿռ�
	// 2.���������ɶ�¶�����
	CheckCapacity(ps);
	// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
	// ��������
	printf("���������֣�>");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��>");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ���\n");
}

void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else {
		int i = 0;
		// ����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		// ����
		for (i = 0; i < ps->size; i++) {
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", 
				ps->data[i].name, 
				ps->data[i].age, 
				ps->data[i].sex, 
				ps->data[i].tele, 
				ps->data[i].addr);
		}
	}
}

// �ҵ�Ԫ���������е��±�λ��
static int FindByName(const struct Contact* ps, char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (0 == strcmp(ps->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("������Ҫɾ�����˵����֣�>");
	scanf("%s", name);
	// 1.����Ҫɾ��������ʲôλ��
	int pos = FindByName(ps, name);
	// 2.ɾ��
	if (pos == -1) {
		printf("Ҫɾ�����˲����ڣ�\n");
	}
	else {
		// ɾ������
		// ����ɾ�������кö෽�������԰����һ��Ԫ��Ų���±�Ϊi��Ԫ���ϣ�Ҳ���԰��±�i֮�������Ԫ�ض���ǰŲһ����λ
		// ��������ʵ�ְ��±�i֮�������Ԫ�ض���ǰŲһ����λ���ַ���
		int j = 0;
		for (j = pos; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}

void SearchContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲����ڣ�\n");
	}
	else {
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		// ����
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ��˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("Ҫ�޸ĵ�����Ϣ�����ڣ�\n");
	}
	else {
		printf("���������֣�>");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ���\n");
	}
}

// �ȽϺ���
static int cmp(const void* a, const void* b) {
	return ((struct PeoInfo*)a)->age - ((struct PeoInfo*)b)->age;
}
void SortContact(struct Contact* ps) {
	qsort(ps->data, ps->size, sizeof(struct PeoInfo), cmp);
}

// ʹ�ö�̬�ڴ����Ľ�����֮����������Ĵ���
void DestroyContact(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}

// ʹ���ļ������Ľ�����֮����������Ĵ���
void SaveContact(struct Contact* ps) {
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL) {
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	// дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}
