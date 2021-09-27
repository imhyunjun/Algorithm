#include <iostream>
using namespace std;

int cnt = 0;
int newN = 0;

void Cycle(int _n)
{
	if (_n < 10)
	{
		_n = _n * 10;
	}

	int q = _n / 10;
	int r = _n % 10;

	int temp = q + r;
	newN = r * 10 + temp % 10;
	cnt++;
}


int main()
{
	int N;
	cin >> N;

	while (N != newN)
	{
		Cycle(N);
	}
	cout << cnt;

	return 0;
}