/*!
 * \file 算法之美--数组.cpp
 *
 * \author ranjiewen
 * \date 2016/11/29 21:18
 *
 * 
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	//一维数组的操作，用下标访问元素
	int a[10] = {1,32,65,2,100,34,33,21,10,1};
	int sum = 0;
	for (int i = 0; i < 10;i++)
	{
		sum += a[i];
	}
	cout << "数组中元素的和为：" << sum << endl;

	//C++不提供对数组边界的检查，越界访问
	int b[5] = {6,7,8,9,10};
	cout << b[6] << endl;   //输出-858993460，程序并不会崩溃

	//二维数组的操作
	int c[][3] = { { 0, 1, 2 }, { 3, 4, 5 }, {6,7,8} }; //第二维的长度不能省略

	//使用指针高效的访问一，二维数据元素并操作
	int *p = &a[0];
	cout << a[0] << endl;
	cout << *p << endl;
	cout << a << endl;
	cout << &a << endl; //注意就是a的地址
	cout << &a[0] << endl;
	cout << p << endl;
	cout << *(p + 4) << endl;  //指针变量的偏移操作
	cout << *(a + 4) << endl;
	p++;
	cout << p << endl;
	(*p)++;
	cout << *p << endl;

	//区别*p++,*(p++),*(++p
	//*和++的运算优先级相同，结合方向为从右向左。
	p = a;  //p可以++操作，但是a不能++操作，a为数组元素的首地址，为常量指针
	cout << *p++ << endl;  
	cout << p << endl;
	cout << *(p++) << endl;
	cout << *(++p) << endl;

	return 0;
}

