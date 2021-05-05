#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

// 使用文件操作改进代码之后增加下面的代码
void LoadContact(struct Contact* ps);
void InitContact(struct Contact* ps) {
	// 使用动态内存分配改进代码之后将下面的代码注释
	// memset(ps->data, 0, sizeof(ps->data));
	// ps->size = 0;
	// 使用动态内存分配改进代码之后增加下面的代码
	// 我们希望初始化的时候通讯录能放下三个人的信息
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	// 使用文件操作改进代码之后增加下面的代码
	// 把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(ps);
}

// 使用文件操作改进代码之后增加下面的代码
// 声明函数
static void CheckCapacity(struct Contact* ps);
void LoadContact(struct Contact* ps) {
	struct PeoInfo temp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL) {
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	// 读取文件，存放到通讯录中
	while (fread(&temp, sizeof(struct PeoInfo), 1, pfRead)) {
		CheckCapacity(ps);
		ps->data[ps->size] = temp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

// 使用动态内存分配改进代码之后增加下面的代码
static void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		// 增容
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功！\n");
		}
		else {
			printf("增容失败！\n");
		}
	}
}

void AddContact(struct Contact* ps) {
	// 使用动态内存分配改进代码之后将下面的代码注释
	// if (ps->size == MAX) {
	// 	 printf("通讯录已满，无法添加！\n");
	// }
	// else {
	// 	printf("请输入名字：>");
	// 	scanf("%s", ps->data[ps->size].name);
	// 	printf("请输入年龄：>");
	// 	scanf("%d", &(ps->data[ps->size].age));
	// 	printf("请输入性别：>");
	// 	scanf("%s", ps->data[ps->size].sex);
	// 	printf("请输入电话：>");
	// 	scanf("%s", ps->data[ps->size].tele);
	// 	printf("请输入地址：>");
	// 	scanf("%s", ps->data[ps->size].addr);
	// 	ps->size++;
	// 	printf("添加成功！\n");
	// }

	// 使用动态内存分配改进代码之后增加下面的代码
	// 检测当前通讯录的容量
	// 1.如果满了，就增加空间
	// 2.如果不满，啥事都不干
	CheckCapacity(ps);
	// 使用动态内存分配改进代码之后增加下面的代码
	// 增加数据
	printf("请输入名字：>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功！\n");
}

void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("通讯录为空！\n");
	}
	else {
		int i = 0;
		// 标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		// 数据
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

// 找到元素在数组中的下标位置
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
	printf("请输入要删除的人的名字：>");
	scanf("%s", name);
	// 1.查找要删除的人在什么位置
	int pos = FindByName(ps, name);
	// 2.删除
	if (pos == -1) {
		printf("要删除的人不存在！\n");
	}
	else {
		// 删除数据
		// 这里删除数据有好多方法，可以把最后一个元素挪到下标为i的元素上，也可以把下标i之后的所有元素都往前挪一个单位
		// 这里我们实现把下标i之后的所有元素都往前挪一个单位这种方法
		int j = 0;
		for (j = pos; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功！\n");
	}
}

void SearchContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要查找的人的名字：>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("要查找的人不存在！\n");
	}
	else {
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		// 数据
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
	printf("请输入要修改的人的名字：>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("要修改的人信息不存在！\n");
	}
	else {
		printf("请输入名字：>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功！\n");
	}
}

// 比较函数
static int cmp(const void* a, const void* b) {
	return ((struct PeoInfo*)a)->age - ((struct PeoInfo*)b)->age;
}
void SortContact(struct Contact* ps) {
	qsort(ps->data, ps->size, sizeof(struct PeoInfo), cmp);
}

// 使用动态内存分配改进代码之后增加下面的代码
void DestroyContact(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}

// 使用文件操作改进代码之后增加下面的代码
void SaveContact(struct Contact* ps) {
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL) {
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	// 写通讯录中数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}
