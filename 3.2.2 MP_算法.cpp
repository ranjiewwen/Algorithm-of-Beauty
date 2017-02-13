/*!
 * \file MP_算法.cpp
 *
 * \author ranjiewen
 * \date 2017/02/12 15:06
 *
 * 
 */

void preMp(const char *pattern, int m, int mpNext[]) //m为pattern的长度
{
	int i, j;
	i = 0;
	j = mpNext[0] = -1;
	while (i<m)
	{
		while (j>-1&&pattern[i]!=pattern[j]) //
		{
			j = mpNext[j];
		}
		mpNext[++i] = ++j;  //mpNext(j)=f(j-1)+1
	}
}

#include <iostream>
#include <string>
using namespace std;

void MP(string pattern, string target)
{
	int m = pattern.length();
	int n = target.length();
	if (m>n)
	{
		cerr << "Unsuccessful match!" << endl;
		return;
	}
	const char* x = pattern.c_str();
	const char* y = target.c_str();
	int i = 0, j = 0, mpNext[128];  //m+1大小

	preMp(x, m, mpNext);  //mpNext 进行一下轮比较过程中模式P的起始比较位置

	bool flag = false;
	while (i<n)   //i 遍历target字符串
	{
		while (j>-1&&x[j]!=y[i])  //j 匹配模式字符串
		{
			j = mpNext[j];
		}
		j++;
		i++;

		if (j>=m)
		{
			cout << "Matching index found at:" << i - j << endl;
			j = mpNext[j];  //匹配后面的子串
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "Unsuccessful match=-====!";
	}
}

int main(int argc, char** argv)
{
	string p1 = "abcabcad";
	string p2 = "adcadcad";
	string p3 = "ababcaabc";
	string t = "ctcabcabcadtcaabcabcaaatabcabcad";

	cout << "MP_p1 : " << endl;
	MP(p1, t);
	cout << endl;

	cout << "MP_p2 : " << endl;
	MP(p2, t);
	cout << endl;

	cout << "MP_p3 : " << endl;
	MP(p3, t);
	cout << endl;

	string t1 = "ctcaatcacaatcat";
	string p4 = "caatcat";
	MP(p4, t1);
	cout << endl;
	return 0;
}