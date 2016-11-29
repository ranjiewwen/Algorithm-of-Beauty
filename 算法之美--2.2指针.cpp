
#include <iostream>
#include <ctime>
using namespace std;

void fun(int _x); //按值传递，不能修改外部变量，函数内部对参数进行备份，效率低
void fun(int *_p);
void fun1(int &_r);//引用传递，传递大对象时高效，注意在传递引用时声明为const类型
void first_bigger(int *p, int threshold);
void first_bigger1(int *&p, int threshold);
int main()
{
	/************************************************************************/
	/*指针变量的使用                                                         */
	/************************************************************************/
	unsigned int a = 5;
	unsigned int *pint = NULL;
	
	cout << "&a=" << &a << endl << "a=" << a << endl;
	cout << "&pint=" << &pint << endl << "pint=" << pint << endl;
	cout << "&(*pint)=" << &(*pint) << endl << endl;

	pint = &a;
	cout << "&a=" << &a << endl << "a=" << a << endl;
	cout << "&pint=" << &pint << endl << "pint=" << pint << endl;
	cout << "&(*pint)=" << &(*pint) << endl << endl;
	 
	*pint = 10;   //改变指针指向的变量的值
	cout << "&a=" << &a << endl << "a=" << a << endl;
	cout << "&pint=" << &pint << endl << "pint=" << pint << endl;
	cout << "&(*pint)=" << &(*pint) << endl << endl;

	/************************************************************************/
	/*函数参数传递                                                           */
	/************************************************************************/
	//按值传递
	int x = 10;
	cout << "x=" << x << endl;
	fun(x);
	cout << "x=" << x << endl;
	//按指针传递
	int y = 5;
	cout << "y=" << y << endl;
	fun(&y);
	cout << "y=" << y << endl;
	//按引用传递
	int z = 0;
	cout << "z=" << z << endl;
	fun1(z);
	cout << "z=" << z << endl;

	/************************************************************************/
	/* 采用引用传递方式来传递一个指针,被传递的指针需要进行重定向时采用           */
	/************************************************************************/
	int numbers[] = {0,12,32,44,35,5,85,45,100,75};
	int *result = &numbers[0];
	cout << "Begin at:" << *result << endl;
	first_bigger(result, 60);
	cout << "Result is:" << *result << endl;  //输出0

	cout << "Begin at:" << *result << endl;
	first_bigger1(result, 60);
	cout << "Result is:" << *result << endl;  //输出85
	return 0;
}

void fun(int _x)
{
	cout << "x=" << _x << endl;
	_x++;
	cout << "x=" << _x << endl;
}

void fun(int *_p)
{
	cout << "*_p=" << *_p << endl;
	(*_p)++;
	cout << "*_p=" << *_p << endl;
}

void fun1(int &_r)
{
	cout << "_r=" << _r << endl;
	_r++;
	cout << "_r=" << _r << endl;
}

void first_bigger(int *p, int threshold)
{
	while (*p<=threshold)
	{
		p++;
	}
}

void first_bigger1(int *&p, int threshold)
{
	while (*p <= threshold)
	{
		p++;
	}
}