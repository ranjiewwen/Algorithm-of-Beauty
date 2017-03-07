/*!
 * \file 循环队列.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 20:23
 *
 * 循环队列用数组实现，达到内存利用好
 */

#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"

#define  N  8

typedef struct queue
{
	int *pBase;  // 数组头指针
	int front;   //指向队列第一个元素
	int rear;    //指向队列的最后一个元素的下一个元素
	int maxsize;
	struct queue(){ pBase = nullptr, front = rear = maxsize = 0; }
}Queque,*LinkQueque;  


void CreateQueque(LinkQueque Q,int maxsize);
void TraverseQueque(LinkQueque Q);
bool FullQueque(LinkQueque Q);
bool EmptyQueque(LinkQueque Q);
bool EnQueque(LinkQueque Q, int val);
bool DeQueque(LinkQueque Q,int *val);


int main()
{
	Queque q; 
	LinkQueque Q=&q;    //初始化变量
	CreateQueque(Q, N);
	for (int i = 1; i <= 6;i++)
	{
		EnQueque(Q, i);
	}
	TraverseQueque(Q);
	EnQueque(Q, 10);
	if (FullQueque(Q))
	{
		TraverseQueque(Q);
		printf("满队列...\n");
	}
	int del_data=0;
	if (DeQueque(Q,&del_data))
	{
		printf("出队列成功，数值为：%d\n", del_data);
	}
	TraverseQueque(Q);

	return 0;
}

void CreateQueque(LinkQueque Q, int maxsize)
{
	Q->pBase = (int*)malloc(sizeof(int)*maxsize);
	if (Q->pBase==nullptr)
	{
		printf("Memory allocation failure...");
		exit(-1);
	}
	Q->front = 0; //初始化参数
	Q->rear = 0;
	Q->maxsize = maxsize;
}

void TraverseQueque(LinkQueque Q)
{
	int i = Q->front;
	printf("队列中的元素为：\n");
	while (i%Q->maxsize!=Q->rear)
	{
		printf("%d ", Q->pBase[i]);
		i=(i+1)%Q->maxsize;
	}
	printf("\n");
}

bool FullQueque(LinkQueque Q)
{
	if (Q->front == (Q->rear + 1) % Q->maxsize)    //判断循环链表是否满，留一个预留空间不用
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EmptyQueque(LinkQueque Q)
{
	if (Q->rear==Q->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EnQueque(LinkQueque Q, int val)
{
	if (FullQueque(Q))
	{
		return false;
	}
	else
	{
		Q->pBase[Q->rear] = val;
		Q->rear = (Q->rear + 1) % Q->maxsize;
		return true;
	}
}

bool DeQueque(LinkQueque Q, int *val)
{
	if (EmptyQueque(Q))
	{
		return false;
	}
	else
	{
		*val = Q->pBase[Q->front];
		Q->front = (Q->front + 1) % Q->maxsize;
		return true;
	}
}