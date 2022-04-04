#include <iostream>
#include <memory.h>
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

int main()
{
	int n;
	memset(fibo, -1, sizeof(fibo));

	cin >> n;
	cout << Fibo(n);
	return 0;
}