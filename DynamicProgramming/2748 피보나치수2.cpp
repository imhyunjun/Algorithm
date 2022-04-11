#include <iostream>
#include <memory.h>
#include <iomanip>
using namespace std;

long long fibo[91];

long long Fibo(int _n)
{
	long long r;

	if (fibo[_n] != -1)
	{
		return fibo[_n];
	}
	else
	{
		if (_n == 0)
		{
			r = 0;
		}
		else if (_n == 1)
		{
			r = 1;
		}
		else
		{
			r = Fibo(_n - 1) + Fibo(_n - 2);
		}

		fibo[_n] = r;
		return r;
	}
}

long long Fibo2(int _n)
{
	long double r1 = (1 + pow(5, 0.5)) / 2;
	long double r2 = (1 - pow(5, 0.5)) / 2;
	return (long long)((pow(r1, _n) - pow(r2, _n)) / pow(5, 0.5));
}

int main()
{
	int n;
	memset(fibo, -1, sizeof(fibo));

	//cin >> n;
	//cout << Fibo(n);
	//cout << Fibo2(n) << endl;
	cout << std::setprecision(17);
	for (int i = 0; i <= 90; i++)
	{
		cout << Fibo(i) << endl;
		cout << Fibo2(i) << endl;
	}
	return 0;
}