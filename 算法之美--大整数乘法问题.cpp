/*!
 * \file 算法之美--大整数乘法问题.cpp
 *
 * \author ranjiewen
 * \date 2016/12/04 15:58
 *
 * 
 */

#include <iostream> 
using namespace std;

#define  SIZE  14

int *multi(int *_num1, int size1, int *_num2, int size2)
{
	int *ret=nullptr;
	int size = size1 + size2;
	ret = new int[size];

	memset(ret, 0, sizeof(int)*size);

	for (int i = 0; i < size1;i ++)
	{
		int k = i;   //关键点
		for (int j = 0; j < size2;j++)
		{
			ret[k++] += _num1[i] * _num2[j];
		}
	}

	for (int i = 0; i < size;i++)
	{
		if (ret[i]>=10)
		{
			ret[i + 1] += ret[i] / 10;  //注意
			ret[i] = ret[i] % 10;
		}
	}
	return ret;
}

int main(int argc, char** agrv[])
{
	int num1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1, 1, 1 };
	int num2[SIZE] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

	int *ret = multi(num1,SIZE,num2,SIZE);

	for (int i = 2 * SIZE - 1; i >= 0;i--)
	{
		cout << ret[i];
	}

	delete[] ret;

	return 0;
}