/*!
 * \file singlist_c.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 12:15
 *
 * 
 */


/*********************************************************************************************************
以下为操作链表的算法，该链表为单链表。
链表以头指针为索引，头指针指向头节点，头节点指向首节点，以此类推，直到尾节点。
头节点中不存放数据，只存放指向首节点的指针，
设置头节点的目的是为了方便对链表的操作，如果不设置头节点，而是直接由头指针指向首节点，
这样在对头指针后的节点进行插入删除操作时就会与其他节点进行该操作时有所不同，便要作为一种特殊情况来分析
**********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
	Node(int data_, Node* pNext_) :data(data_), pNext(pNext_){}

}Node,*pNode;

pNode CreateList();
void TraverseList(pNode);
bool IsEmpty(pNode);
int LengthList(pNode);
void SortList(pNode);
bool InsertList(pNode, int, int);
bool DeleteList(pNode, int, int*);
void ClearList(pNode);

int main()
{
	int len = 0;
	int data_del;
	pNode pHead = nullptr;
	//创建链表并遍历输出
	pHead = CreateList();
	TraverseList(pHead);

	//求链表长度并输出
	len = LengthList(pHead);
	if (!IsEmpty(pHead))
	{
		printf("This list's length is: %d\n", len);
	}

    //向链表中插入数据并重新遍历输出
	if (InsertList(pHead,3,78))
	{
		printf("Insert successful!");
	}
	else
	{
		printf("Insert failed!");
	}
	TraverseList(pHead);

	//从链表中删除数据并重新遍历输出
	if (DeleteList(pHead,3,&data_del))
	{
		printf("delete succeed,the deleted data is : %d\n", data_del);
	}
	else
	{
		printf("delete failed!");
	}
	TraverseList(pHead);

	//对链表排序，重新遍历输出
	SortList(pHead);
	printf("After sorted:");
	TraverseList(pHead);

	//清空链表，遍历输出
	ClearList(pHead);
	printf("After cleared:");
	TraverseList(pHead);
	
	return 0;
}

//创建链表，返回头指针
pNode CreateList()
{
	int value;
	pNode pHead = (pNode)malloc(sizeof(Node));
	pNode pCur = pHead;
	pCur->pNext = nullptr;
	if (pHead==nullptr)
	{
		printf("pHead malloc failed!");
		exit(-1);
	}
	printf("Input the first data(q to quit):");
	while (scanf("%d",&value)==1)
	{
		pNode pNew = (pNode)malloc(sizeof(Node));
		if (pNew==nullptr)
		{
			printf("pNew malloc failed!");
			exit(-1);
		}
		pNew->data = value;
		pNew->pNext = nullptr;
		pCur->pNext = pNew;
		pCur = pNew;  //移动当前节点到下一位置
		printf("Input next data(q to quit):");
	}
	return pHead;
}

//遍历链表
void TraverseList(pNode pHead)
{
	pNode pCur = pHead->pNext;
	printf("Now datas in the list are:\n");
	while (pCur!=nullptr)
	{
		printf(" %d  ", pCur->data);
		pCur = pCur->pNext;
	}
	printf("\n");
	return;
}

//判断链表是否为空
bool IsEmpty(pNode pHead)
{
	if (pHead->pNext!=nullptr)
	{
		return false;
	}
	return true;
}

//求链表的长度（不计入头结点）
int LengthList(pNode pHead)
{
	int len = 0;
	while (pHead->pNext!=nullptr)
	{
		len++;
		pHead = pHead->pNext;
	}
	return len;
}

//冒泡法对链表排序
void SortList(pNode pHead)
{
	pNode q, p;
	int temp;
	for (p = pHead->pNext; p != nullptr;p=p->pNext)
	{
		for (q = p->pNext; q != nullptr;q=q->pNext)
		{
			if (p->data>q->data) //从小到大排序
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
	return;
}

//在第pos个节点的后面插入一个新的节点，该节点数据为val
bool InsertList(pNode pHead, int pos, int val)
{
	if (pHead==nullptr)
	{
		return false; //或者pos大于链表长度
	}
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (pNew==nullptr)
	{
		printf("new malloc failed!");
		exit(-1);
	}
	pNew->data = val;

	pNode pCur = pHead;
	while (--pos)
	{
		pCur = pCur->pNext;
	}
	pNew->pNext = pCur->pNext;
	pCur->pNext = pNew;

	return true;
}

//删除第pos个节点，并将删除的数据保存在pData所指向的位置
bool DeleteList(pNode pHead, int pos, int* pdata)
{
	pNode pCur = pHead;
	int i = 0;
	while (i<pos-1&&pCur->pNext!=nullptr)
	{
		pCur = pCur->pNext;
		i++;
	}

	if (pHead==nullptr||i>pos-1)
	{
		return false;
	}

	pNode pDel = pCur->pNext;
	pCur->pNext = pDel->pNext;
	*pdata = pDel->data;
	free(pDel);
	pDel = nullptr;

	return true;
}

//清空链表，即只剩下头结点，头结点没有数据
void ClearList(pNode pHead)
{
	pNode pCur=pHead->pNext;
	pNode ptemp=nullptr;
	while (pCur)
	{
		ptemp = pCur->pNext;  //用一个新的指针变量保存
		free(pCur);
		pCur = ptemp;
	}
	pHead->pNext = nullptr;
	return;
}

