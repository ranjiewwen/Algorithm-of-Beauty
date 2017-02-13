
/*!
 * \file 编辑距离.cpp
 *
 * \author ranjiewen
 * \date 2017/02/13 20:51
 *
 */

#include<stdio.h>
#include <string.h>
#include <malloc.h>

void backtracking(int**, char*, char*);    //回溯，计算出如何通过其中一个字符串的变换，得到另外一个字体串
int ** build_matrix(char*, char*);         //求编辑距离,返回一个已经填充好的矩阵
int trigle_min(int a, int b, int c);       //求三个数的最小值


int main()
{
	char* A = "GGATCGA";
	char* B = "GAATTCAGTTA";
	int** matrix = build_matrix(A, B);
	printf("A和B的编辑距离为：%d\n", matrix[strlen(A)][strlen(B)]);
	backtracking(matrix, A, B);
	free(matrix);
	return 0;
}

//0 左上角 ,1上方,-1左边
int way(int i_t, int j_t, int i, int j)
{
	if (i - i_t == 1 && j - j_t == 1) {
		return 0;
	}
	if (i - i_t == 1 && j - j_t == 0) {
		return 1;
	}
	if (i - i_t == 0 && j - j_t == 1) {
		return -1;
	}
}

int** build_matrix(char* A, char* B)
{
	int m = strlen(A);
	int n = strlen(B);
	int** matrix = (int**)malloc(sizeof(int*)*(m + 1));
	int i, j;
	for (i = 0; i < m + 1; i++)
	{
		*(matrix + i) = (int*)malloc(sizeof(int)*(n + 1));
	}
	matrix[0][0] = 0;
	for (i = 1; i < n + 1; i++)
	{
		matrix[0][i] = i;
	}
	for (i = 1; i < m + 1; i++)
	{
		matrix[i][0] = i;
	}

	for (i = 1; i < m + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (*(A + i - 1) == *(B + j - 1))
			{
				matrix[i][j] = matrix[i - 1][j - 1];
			}
			else
			{
				matrix[i][j] = trigle_min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
			}
		}
	}
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return matrix;
}

void backtracking(int** matrix, char* A, char *B) {
	int m = strlen(A);
	int n = strlen(B);
	int i = m;
	int j = n;
	int max = m > n ? m : n;
	char* p = (char*)malloc(sizeof(char)*m);
	char* q = (char*)malloc(sizeof(char)*m);
	int k = 0;
	while (i > 0 && j > 0)
	{
		if (*(A + i - 1) == *(B + j - 1))
		{
			*(p + k) = *(A + i - 1);
			*(q + k) = *(B + j - 1);
			--i;
			--j;
			++k;
		}
		else
		{
			int i_t = 0; //取三个方向上值小的坐标
			int j_t = 0;
			if (matrix[i][j - 1] >= matrix[i - 1][j])
			{
				i_t = i - 1;
				j_t = j;
			}
			else {
				i_t = i;
				j_t = j - 1;
			}
			if (matrix[i_t][j_t] >= matrix[i - 1][j - 1])
			{
				i_t = i - 1;
				j_t = j - 1;
			}
			/////////      
			int w = way(i_t, j_t, i, j);
			if (w == 0)  {
				*(p + k) = *(A + i - 1);
				*(q + k) = *(B + j - 1);
			}
			else if (w == -1) {
				*(p + k) = '-';
				*(q + k) = *(B + j - 1);
			}
			else {
				*(p + k) = *(A + i - 1);
				*(q + k) = '-';
			}
			++k;
			i = i_t;
			j = j_t;
		}
	}
	if (i == 0) {
		*(q + k) = *(B + j - 1);
		*(q + k) = '-';

	}
	else {
		*(p + k) = *(A + i - 1);
		*(q + k) = '-';

	}
	for (i = max - 1; i >= 0; i--) {
		printf("%c", *(p + i));
	}
	printf("\n");
	for (i = max - 1; i >= 0; i--) {
		printf("%c", *(q + i));
	}
}

int trigle_min(int a, int b, int c)
{
	int min = a < b ? a : b;
	return min < c ? min : c;
}


//////////////////////////////////////////////////////////////////////////
//C++
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//
//int edit(string str1, string str2)
//{
//	int max1 = str1.size();
//	int max2 = str2.size();
//
//	int **ptr = new int*[max1 + 1];
//	for (int i = 0; i < max1 + 1; i++)
//	{
//		ptr[i] = new int[max2 + 1];
//	}
//
//	for (int i = 0; i < max1 + 1; i++)
//	{
//		ptr[i][0] = i;
//	}
//
//	for (int i = 0; i < max2 + 1; i++)
//	{
//		ptr[0][i] = i;
//	}
//
//	for (int i = 1; i < max1 + 1; i++)
//	{
//		for (int j = 1; j < max2 + 1; j++)
//		{
//			int d;
//			int temp = min(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
//			if (str1[i - 1] == str2[j - 1])
//			{
//				d = 0;
//			}
//			else
//			{
//				d = 1;
//			}
//			ptr[i][j] = min(temp, ptr[i - 1][j - 1] + d);
//		}
//	}
//
//	cout << "**************************" << endl;
//	for (int i = 0; i < max1 + 1; i++)
//	{
//		for (int j = 0; j < max2 + 1; j++)
//		{
//			cout << ptr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "**************************" << endl;
//	int dis = ptr[max1][max2];
//
//	for (int i = 0; i < max1 + 1; i++)
//	{
//		delete[] ptr[i];
//		ptr[i] = NULL;
//	}
//
//	delete[] ptr;
//	ptr = NULL;
//
//	return dis;
//}
//
//int main(void)
//{
//	string str1 = "sailn";
//	string str2 = "failing";
//
//	int r = edit(str1, str2);
//	cout << "the dis is : " << r << endl;
//
//	return 0;
//}