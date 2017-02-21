
#include <iostream>  
#include "SingleList.h"  

using namespace std;

int main()
{
	SingleList<int> list;
	for (int i = 0; i < 9; i++)
		list.AddTail(i);

	cout << list.GetCount() << endl;

	cout << list.GetAt(3) << endl;

	list.RemoveAt(3);

	cout << list.GetCount() << endl;
	cout << list.GetAt(3) << endl;

	list.RemoveAll();
	cout << list.GetCount() << endl;

	system("PAUSE");
	return 0;
}