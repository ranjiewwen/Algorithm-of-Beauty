/*!
 * \file 算法之美--4.3.4 魔术师发牌问题.cpp
 * \date 2017/02/25 15:58
 *
 * \author ranjiewen
 *
 * \brief 问题描写叙述：
			 魔术师手中有A、2、3……J、Q、K十三张黑桃扑克牌。在表演魔术前，魔术师已经将他们依照一定的顺序叠放好（有花色的一面朝下）。
			 魔术表演过程为：一開始，魔术师数1，然后把最上面的那张牌翻过来，是黑桃A；然后将其放到桌面上；第二次,魔术师数1、2；
			 将第一张牌放到这些牌的最以下，将第二张牌翻转过来，正好是黑桃2；第三次，魔术师数1、2、3；将第1、2张牌依次放到这些牌的最以下，将第三张牌翻过来正好是黑桃3；
			 ……直到将全部的牌都翻出来为止。问原来牌的顺序是怎样的。
 *
 * TODO: long description
 *
 * \note
*/

#include <iostream>
using namespace std;

#define N 13

typedef struct Node
{
	int data;
	Node* pNext;
	Node(int data_ = 0, Node* pNext_ = nullptr) :data(data_), pNext(pNext_){}
}Node,*LinkList;




void InitLinkList(LinkList&L,int n) //创建并初始化循环链表，L表示表头节点，n创建节点元素的个数
{
	L = (Node*)malloc(sizeof(Node));
	L->pNext = L; //头结点循环
	LinkList p;
	for (int j = 0; j < n; j++)  //一直在头结点插入
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = 0;
		p->pNext = L->pNext;//插入节点指向头结点
		L->pNext = p; //头结点指向新的节点
	}
	return;
}

void Magician(LinkList& L, int n) //魔术师问题求解
{
	LinkList p = L->pNext;
	p->data = 1;//第一张为1；
	for (int num = 2; num <= n;num++) //依次找到2-n牌的位置
	{
		int i = 0;
		while (i<num)
		{
			p = p->pNext;
			if (p->data==0) //跳过有牌的位置，没有牌的才加1
			{
				i++;
			}
		}
		p->data = num;
	}
}

void Print(LinkList&L)
{
	LinkList p = L->pNext;
	cout << "Print:";
	while (p!=L)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

int main()
{
	LinkList L;
	InitLinkList(L,N);
	Magician(L,N);
	Print(L);
	return 0;
}