
#ifndef SINGLELIST_LISTNODE_H_
#define SINGLELIST_LISTNODE_H_

template <class T>
class ListNode
{
public: //定义为private时，所以在会用到访问
	T data;
	ListNode<T> * pNext;
public:
    ListNode() : pNext(nullptr){}
	ListNode(T value_) :data(value_), pNext(nullptr){}
	~ListNode(){}

	void SetpNext(ListNode<T>* next_);
	void SetData(T value_);
	ListNode<T>* GetpNext();
	T& GetData();
};

template <class T>
void ListNode<T>::SetpNext(ListNode<T>* next_)
{
	pNext = next_;
}

template<class T>
void ListNode<T>::SetData(T value_)
{
	data = value_;
}

template<class T>
ListNode<T>* ListNode<T>::GetpNext()
{
	return pNext;
}

template<class T>
T& ListNode<T>::GetData()
{
	return data;
}

#endif

