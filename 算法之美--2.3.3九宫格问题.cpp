
/*!
 * \file 九宫格问题.cpp
 *
 * \author ranjiewen
 * \date 十二月 2016
 *
 * 
 */

#include<iostream>
#include<iomanip>

using namespace std;

int main(int agrc, char **argv[])
{
	cout << "请输入幻方的小大n(大于1的奇数):" << endl;
	int n = 1;
	cin >> n;
	cout << endl;
	int **a = new int*[n];
	for (int i = 0; i < n;i++)
	{
		a[i] = new int[n];
		memset(a[i],0,n*sizeof(int));
	}
	int row = 0;
	int col = n / 2;

	for (int i = 1; i <= n*n;i++)
	{
		a[row][col] = i;
		row--;
		col++;
		if (row<0&&col>=n)
		{
			col--;
			row += 2;
		}
		else if (row < 0)
		{
			row = n - 1;
		}
		else if (col>=n)
		{
			col = 0;
		}
		else if (a[row][col]!=0)
		{
			col--;
			row += 2;
		}
	}

	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			cout << setw(6) << a[i][j];
		}
		cout << endl;
	}
	for (int i = n-1; i >0 ; i--)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}
