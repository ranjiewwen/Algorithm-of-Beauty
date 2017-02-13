
#include<iostream>
using namespace std;
#include <string>

#define  N_GRAM

int N_gram(string x, string y, int n) {

	int lp = x.length();
	int lt = y.length();

	int num_x = lp - n + 1;
	int num_y = lt - n + 1;
	int num_s = 0;

	for (int i = 0; i < num_x; i=i+1){
		string sub_str = x.substr(i, n);
		if (y.find(sub_str) != -1)
			num_s++;
	}

	return num_x + num_y - 2 * num_s;
}

#ifdef N_GRAM

int main(int argc, char** argv) {

	int N = 2;

	string p = "Gorbachev";
	string t = "Gorbechyov";

	cout << N_gram(p, t, N) << endl;

	return 0;
}

#endif




