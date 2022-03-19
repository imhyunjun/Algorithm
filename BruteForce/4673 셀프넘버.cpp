#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

int selfNum[10001];

int SelfNum(int _n)
{
	int self = _n;

	for (int i = 1; i < 5; i++)
	{
		int divisor = pow(10, i);
		int divisor2 = pow(10, i - 1);
		if (_n < divisor2) break;
		self += (_n % divisor) / divisor2;
	}
	return self;
}

int main()
{
	memset(selfNum, 1, sizeof(selfNum));

	for (int i = 1; i <= 10000; i++)
	{
		int self = SelfNum(i);
		if (self <= 10000)
		{
			selfNum[self] = 0;
		}
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (selfNum[i])
			cout << i << "\n";
	}

	return 0;
}