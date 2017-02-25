
/*!
 * \file 算法之美--4.3.3 约瑟夫环问题.cpp
 *
 * \author ranjiewen
 * \date 2017/02/25 14:31
 *
 * 单循环链表的使用
 */

#include<stdio.h>
#include <malloc.h>

#include <iostream>
using namespace std;
#include <list>

//使用STL标准库
int Josephusproblem(int n, int m)
{
	if (n<1||m<1)
	{
		return -1;
	}
	list<int> listInt;
	for (int i = 0; i < n;i++)
	{
		listInt.push_back(i+1);
	}
	list<int>::iterator iteCur = listInt.begin();
	while (listInt.size()>1)
	{
		//前进m-1步
		for (int i = 0; i < m - 1;i++)  //0开始
		{
			iteCur++;
			if (iteCur==listInt.end())
			{
				iteCur = listInt.begin();// 循环链表
			}
		}
		//临时保存删除的节点
		list<int>::iterator iteDel = iteCur;
		if (++iteCur==listInt.end())
		{
			iteCur = listInt.begin();
		}
		cout << *iteDel << " ";
		listInt.erase(iteDel);
	}
	cout << endl;
	return *iteCur;
}



typedef struct List
{
	int data;
	struct List* pNext;

	struct List(int data_ = 0, struct List* pNext_ = nullptr){ data = data_; pNext = pNext_; }

}CirSinglist;


int main()
{
	CirSinglist *pHead, *pCur, *pTemp;
	pHead = (CirSinglist*)malloc(sizeof(CirSinglist));
	pCur = pHead;
	int n, m;
	printf("请输出 n，m的值：\n");
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n;i++) //创建链表
	{
		pTemp = (CirSinglist*)malloc(sizeof(CirSinglist));
		pTemp->data = i;
		pTemp->pNext = nullptr;
		pCur->pNext = pTemp;
		pCur = pTemp;
	}
	pCur->pNext = pHead->pNext;

	//开始模拟游戏
	CirSinglist *p;
	p = pHead->pNext;
	while (p->pNext!=p)
	{
		for (int i = 1; i < m - 1;i++) //删除节点的前一节点
		{
			p = p->pNext;
		}
		//依次删除的数
		printf("%d ", p->pNext->data);

		p->pNext = p->pNext->pNext;
		//移动指针p
		p = p->pNext;
	}
	printf("\nlast win num:%d \n", p->data);

	cout << "使用标准库函数：" << endl;
	cout << "last win :"<<Josephusproblem(n, m) << endl;

	return 0;
}

