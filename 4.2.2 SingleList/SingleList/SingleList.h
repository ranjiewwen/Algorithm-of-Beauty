
#ifndef  SINGLELIST_SINGLELIST_H_
#define  SINGLELIST_SINGLELIST_H_

#include "ListNode.h"

template<class T>
class SingleList
{
private:
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	SingleList();
	~SingleList();

	bool AddTail(T value_);
	bool RemoveTail();
	bool InsertAt(int index_, T value_);
	bool RemoveAt(int index_);

	T& GetAt(int index_);
	bool IsEmpty();
	int GetCount();
	void RemoveAll();

	ListNode<T>* GetHead();
	ListNode<T>* GetTail();
	ListNode<T>* GetNodeAt(int index_);
	ListNode<T>* GetCur();
	ListNode<T>* TowardCur();

};


template<class T>
bool SingleList<T>::AddTail(T value_)
{
	ListNode<T>* pointer = new ListNode<T>(value_);
	tail->SetpNext(pointer);
	tail = tail->pNext;
	tail->pNext = nullptr;
	if (tail != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
//在索引值指向的节点前插入新节点
bool SingleList<T>::InsertAt(int index_, T value_)
{
	if (index_ > this->GetCount() || index_ < 0)
	{
		cerr << "A wrong position!\n";
		return false;
	}

	ListNode<T>* current = head;
	while (index_)
	{
		current = current->pNext;
		index_--;
	}
	ListNode<T>* add = new ListNode<T>(value_);
	add->pNext = current->pNext;
	current->pNext = add;

	if (current != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool SingleList<T>::RemoveTail()
{
	return RemoveAt(this->GetCount() - 1);
}

template<class T>
bool SingleList<T>::RemoveAt(int index_)
{
	if (index_ > this->GetCount() || index_ < 0)
	{
		cerr << "A wrong position!\n";
		return false;
	}
	ListNode<T>* current = head;
	while (index_ - 1)
	{
		current = current->pNext;
		index_--;
	}
	ListNode<T>* deletePoint = current->pNext;

	if (current->pNext->pNext == nullptr)
	{
		current->pNext = nullptr;
	}
	else
		current->pNext = current->pNext->pNext;
	delete deletePoint;
	return true;
}

template<class T>
SingleList<T>::SingleList()
{
	head = new ListNode<T>();
	tail = head;
	tail->pNext = NULL;
}

template<class T>
SingleList<T>::~SingleList()
{
	RemoveAll();
	delete head;
}

template<class T>
T& SingleList<T>::GetAt(int index_)
{
	if (index_ > GetCount() || index_ < 0)
	{
		cerr << "A wrong position!\n";
	}
	ListNode<T>* cur;
	cur = head->pNext;
	while (index_)
	{
		cur = cur->pNext;
		index_--;
	}
	return cur->GetData();
}

template<class T>
bool SingleList<T>::IsEmpty()
{
	return head->pNext == NULL;
}

template<class T>
int SingleList<T>::GetCount()
{
	int count = 0;
	ListNode<T>* cur = head->pNext;
	while (cur != nullptr)
	{
		cur = cur->pNext;
		count++;
	}
	return count;
}

template<class T>
void SingleList<T>::RemoveAll()
{
	ListNode<T>* cur;
	while (head->pNext != nullptr)
	{
		cur = head->pNext;
		head->pNext = cur->pNext;
		delete cur;
	}
	tail = head;
}

template<class T>
ListNode<T> * SingleList<T>::GetNodeAt(int index_)
{
	if (index_ > this->GetCount() - 1 || index_ < 0)
	{
		cerr << "A wrong position!\n";
	}
	ListNode<T>* handle = head->pNext;
	while (index_)
	{
		handle = handle->pNext;
		index_--;
	}
	return handle;
}

template <class T>
ListNode<T>* SingleList<T>::GetHead(){//返回头指针  
	return head;
}

template <class T>
ListNode<T>* SingleList<T>::GetTail(){//返回尾指针  
	return tail;
}

template <class T>
ListNode<T>* SingleList<T>::GetCur(){
	return cur;
}

template <class T>
ListNode<T>* SingleList<T>::TowardCur(){
	cur = cur->GetLink();
	return cur
}

#endif

