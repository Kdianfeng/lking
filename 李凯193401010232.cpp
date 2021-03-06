// 060304.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <Windows.h>
typedef struct makings {
	char id[15]; //编号
	char name[30]; //名称
	double value; //单价
	int num; //入库数量
	int nownums; //库存数量
	int outs; //出库数量
	char worker[30]; //保管人 
	char intime[20]; //进货时间
	char outtime[20]; //出货时间
	char other[30]; //备注 
}mak;
typedef struct link {
	mak date;
	struct link *next;
}link;

link *head = NULL;

//添加记录
void insert() {
	link *t=NULL;
	int temp;
	while (1) {
		t = (link*)malloc(sizeof(link));
		printf("输入材料编号：");
		scanf_s("%s", t->date.id,15);
		printf("输入材料名称：");
		scanf_s("%s", t->date.name,30);
		printf("输入材料单价：");
		scanf_s("%lf", &t->date.value);
		printf("输入材料入库数量：");
		scanf_s("%d", &t->date.num);
		printf("输入材料库存数量：");
		scanf_s("%d", &t->date.nownums);
		printf("输入材料出库数量：");
		scanf_s("%d", &t->date.outs);
		printf("输入材料保管人：");
		scanf_s("%s", t->date.worker,30);
		printf("输入材料进货时间：");
		scanf_s("%s", t->date.intime,20);
		printf("输入材料出货时间：");
		scanf_s("%s", t->date.outtime,20);
		printf("输入材料备注：");
		scanf_s("%s", t->date.other,30);
		if (head == NULL) {
			head = t;
			head->next = NULL;
		}
		else {
			t->next = head;
			head = t;
		}
		printf("添加成功！\n");
		printf("输入0退出,输入其他数字继续输入：");
		scanf_s("%d", &temp);
		if (temp == 0) {
			break;
		}
	}
	system("pause");
}

//查看所有材料信息
void display() {
	link *t = head;
	printf("%10s %15s %10s %8s %8s %8s %15s %10s %10s %20s \n", "材料编号", "材料名称", "材料单价", "入库数量", "库存数量", "出库数量", "保管人", "进货时间", "出货时间", "备注");
	while (t != NULL) {
		printf("%10s %15s %10.2lf %8d %8d %8d %15s %10s %10s %20s \n", t->date.id, t->date.name, t->date.value, t->date.num, t->date.nownums, t->date.outs, t->date.worker, t->date.intime, t->date.outtime, t->date.other);
		t = t->next;
	}
	system("pause");
}
//查询记录
void find() {
	char temp[20];
	int s = 0;
	link *t = head;
	printf("输入要查询的材料名称：");
	scanf_s("%s", temp,20);
	printf("%10s %15s %10s %8s %8s %8s %15s %10s %10s %20s \n", "材料编号", "材料名称", "材料单价", "入库数量", "库存数量", "出库数量", "保管人", "进货时间", "出货时间", "备注");
	while (t != NULL) {
		if (strcmp(temp, t->date.name) == 0) {
			s++;
			printf("%10s %15s %10.2lf %8d %8d %8d %15s %10s %10s %20s \n", t->date.id, t->date.name, t->date.value, t->date.num, t->date.nownums, t->date.outs, t->date.worker, t->date.intime, t->date.outtime, t->date.other);
		}
		t = t->next;
	}
	printf("共查找到%d个材料信息！\n", s);
	system("pause");
}
//修改记录
void change() {
	char temp[20];
	link *t = head;
	printf("输入要修改的材料编号：");
	scanf_s("%s", temp,20);
	while (t != NULL) {
		if (strcmp(temp, t->date.id) == 0) {
			printf("%10s %15s %10s %8s %8s %8s %15s %10s %10s %20s \n", "材料编号", "材料名称", "材料单价", "入库数量", "库存数量", "出库数量", "保管人", "进货时间", "出货时间", "备注");
			printf("%10s %15s %10.2lf %8d %8d %8d %15s %10s %10s %20s \n", t->date.id, t->date.name, t->date.value, t->date.num, t->date.nownums, t->date.outs, t->date.worker, t->date.intime, t->date.outtime, t->date.other);
			printf("输入修改后的信息：\n");
			printf("输入材料名称：");
			scanf_s("%s", t->date.name,30);
			printf("输入材料单价：");
			scanf_s("%lf", &t->date.value);
			printf("输入材料入库数量：");
			scanf_s("%d", &t->date.num);
			printf("输入材料库存数量：");
			scanf_s("%d", &t->date.nownums);
			printf("输入材料出库数量：");
			scanf_s("%d", &t->date.outs);
			printf("输入材料保管人：");
			scanf_s("%s", t->date.worker,30);
			printf("输入材料进货时间：");
			scanf_s("%s", t->date.intime,20);
			printf("输入材料出货时间：");
			scanf_s("%s", t->date.outtime,20);
			printf("输入材料备注：");
			scanf_s("%s", t->date.other,30);
			printf("修改成功！\n");
			system("pause");
			return;
		}
		t = t->next;
	}
	printf("无此材料信息！\n");
	system("pause");
}
//删除材料信息
void del() {
	char temp[20];
	link *t = head;
	link *p;
	printf("输入要删除的材料编号：");
	scanf_s("%s", temp,20);
	while (t != NULL) {
		if (strcmp(temp, head->date.id) == 0) {
			t = head;
			head = head->next;
			free(t);
			printf("删除成功！\n");
			system("pause");
			return;
		}
		p = t;
		t = t->next;
		if (strcmp(temp, t->date.id) == 0) {
			p->next = t->next;
			free(t);
			printf("删除成功！\n");
			system("pause");
			return;
		}
	}
	printf("无此材料信息！\n");
	system("pause");
}
//从文件中读取信息
void file_read() {
	FILE *fp=NULL;
	int err;
	link *t = NULL;
	t = (link*)malloc(sizeof(link));
	t->next = NULL;
	err = fopen_s(&fp,"date.txt", "r");
	while (EOF != fscanf_s(fp, "%s %s %lf %d %d %d %s %s %s %s", t->date.id,15, t->date.name, 30, &t->date.value, &t->date.num, &t->date.nownums, &t->date.outs, t->date.worker, 30, t->date.intime, 20, t->date.outtime, 20, t->date.other,30)) {
		if (head == NULL) {
			head = t;
			head->next = NULL;
		}
		else {
			t->next = head;
			head = t;
		}
		t = (link*)malloc(sizeof(link));
		t->next = NULL;
	}
	fclose(fp);
}
//将数据保存到文件中
void file_write() {
	FILE *fp;
	int err;
	link *t = head;
	err = fopen_s(&fp,"date.txt", "w");
	while (t != NULL) {
		fprintf(fp, "%s %s %lf %d %d %d %s %s %s %s\n", t->date.id, t->date.name, t->date.value, t->date.num, t->date.nownums, t->date.outs, t->date.worker, t->date.intime, t->date.outtime, t->date.other);
		t = t->next;
	}
	fclose(fp);
}
//菜单
void menu() {
	system("cls");
	printf("----------材料管理系统----------\n");
	printf("          1.添加材料信息\n");
	printf("          2.查看材料信息\n");
	printf("          3.查询材料信息\n");
	printf("          4.修改材料信息\n");
	printf("          5.删除材料信息\n");
	printf("          0.退出系统\n");
	printf("输入你的选择：");
}
int main() {
	int flag;
	file_read();
	while (1) {
		menu();
		scanf_s("%d", &flag);
		if (flag == 1) {
			insert();
		}
		else if (flag == 2) {
			display();
		}
		else if (flag == 3) {
			find();
		}
		else if (flag == 4) {
			change();
		}
		else if (flag == 5) {
			del();
		}
		else if (flag == 0) {
			break;
		}
	}
	file_write();
	return 0;
}

