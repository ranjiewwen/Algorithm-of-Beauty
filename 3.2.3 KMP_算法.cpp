/*!
 * \file KMP_Ëã·¨.cpp
 *
 * \author ranjiewen
 * \date 2017/02/12 16:12
 *
 */

void preKmp(const char* pattern, int m, int kmpNext[])
{
	int i, j;
	i = 0;
	j = kmpNext[0] = -1;
	while (i<m)
	{
		while (j>-1&&pattern[i]!=pattern[j])
		{
			j = kmpNext[j];
		}
		i++;
		j++;
		if (pattern[i]==pattern[j])
		{
			kmpNext[i] = kmpNext[j];
		}
		else
		{
			kmpNext[i] = j;
		}
	}
}

#include <iostream>
using namespace std;
#include <string>

void KMP(string p, string t)
{
	int m = p.length();
	int n = t.length();
	if (m>n)
	{
		cerr << "Unsuccessful match!";
	}
	const char* x = p.c_str();
	const char* y = t.c_str();

	int i = 0, j = 0, kmpNext[128];
	preKmp(x, m, kmpNext);

	i = j = 0;
	while (i<n)
	{
		while (j>-1&&x[j]!=y[i])
		{
			j = kmpNext[j];
		}
		j++;
		i++;
		if (j>=m)
		{
			cout << "Matching index found at:" << i - j << endl;
			j = kmpNext[j];
		}
	}
}

int main(int argc, char** argv) {

	string p1 = "abcabcad";
	string p2 = "adcadcad";
	string p3 = "ababcaabc";
	string t = "ctcabcabcadtcaabcabcadat";

	cout << "KMP: " << endl;
	KMP(p1, t);

	//  cout<<"KMP: "<<endl;  
	//  KMP(p2, t);  

	//  cout<<"KMP: ";  
	//  KMP(p3, t);  

	return 0;
}