
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	const int MAX_TIMES = 20000000;
	srand(static_cast<unsigned int>(time(0)));
	
	int in=0;
	for (int i = 0; i < MAX_TIMES;i++)
	{
		double x = static_cast<double>(rand()) / RAND_MAX;
		double y = static_cast<double>(rand()) / RAND_MAX;
		if (x*x+y*y<=1.0)
		{
			in++;
		}
		if (i%(MAX_TIMES/100)==0)
		{
			cout << ".";
		}
	}
	double pi = 4.0*in / MAX_TIMES;
	cout << "\nPI=" << pi << endl;
	return 0;
}