/*!
 * \file 算法之美--4.3.5 拉丁方阵问题.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 17:02
 *
 * 
 */

/************************************************************************/
/* 拉丁方阵问题
 问题描写叙述：
 拉丁方阵是一种n×n的方阵，方阵中恰有n种不同的元素，每种元素恰有n个，而且每种元素在一行和一列中 恰好出现一次。
 著名数学家和物理学家欧拉使用拉丁字母来作为拉丁方阵里元素的符号，拉丁方阵因此而得名。
 比如:
 1      2      3
 2      3      1
 3      1      2
 问题：怎样构造N阶拉丁方阵？                                              */               
/************************************************************************/

////普通代码,（N阶全部拉丁方阵）
//#include <iostream>
//using namespace std;
//
//#define N 6
//int main()
//{
//	int i, j, k, t;
//	printf("The possible Latin Squares of order %d are:\n", N);
//	for (j = 0; j < N;j++) /*构造N个不同的拉丁方阵*/
//	{
//		for (i = 0; i < N;i++)
//		{
//			t = (i + j) % N; /*确定该拉丁方阵第i 行的第一个元素的值*/
//			for (k = 0; k < N; k++) /*依照环的形式输出该行中的各个元素*/
//				cout << (k + t) % N + 1;
//			cout << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}Node;

typedef struct Node* LinkList;

//构造一个带有N个节点的循环链表
Node* CreateList(Node* L, int n)
{
	Node *pCur, *pTemp;
	L = (LinkList)malloc(sizeof(Node));
	L->pNext = nullptr;
	pCur = L;//当前节点指向表头
	for (int i = 1; i <= n;i++)
	{
		pTemp = (LinkList)malloc(sizeof(Node));
		pTemp->data = i;
		pTemp->pNext = pCur->pNext;
		pCur->pNext = pTemp;
		pCur = pTemp;  //在尾部插入
	}
	pCur->pNext = L->pNext; //循环结构
	return L->pNext;
}

//实现拉丁方阵的输出
void print(struct Node *La, int n)
{
	int i, j;
	struct Node *p, *q;
	p = La;
	for (i = 1; i <= n; i++)
	{
		q = p;
		for (j = 1; j <= n; j++)
		{
			printf("%3d", q->data);
			q = q->pNext;
		}
		printf("\n");
		p = p->pNext;
	}
}

int main(int argc, char* argv[])
{
	int m;
	struct Node *L=nullptr, *t=nullptr;
	//while (1)
	{
		printf("****************************************************\n");
		printf("*****          ESC键：    退出程序             *****\n");
		printf("*****                                          *****\n");
		printf("*****          其他任意键：打印df拉丁方阵        *****\n");
		printf("****************************************************\n");
		/*	if (_getch() == 27)
				break;
				else*/
		{
			printf("\n请输入您要打印的拉丁方阵规模（要打印的行数）：\n\n");
			scanf("%d", &m);
			L = CreateList(L, m);
			printf("\n您输入的规模为%d，打印的方阵如下：\n\n", m);
			print(L, m);
			printf("\n请输入任意键继续：\n");
			_getch();
			system("cls");
		}
	}
	return 0;
}






