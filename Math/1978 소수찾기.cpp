#include <iostream>

using namespace std;

int N;
int cnt = 0;

bool Prime(int _n)
{
	if (_n == 1) return false;
	if (_n == 2) return true;

	for (int i = 2; i * i <= _n; i++)
	{
		if (_n % i == 0) return false;
	}

	return true;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		if (Prime(p))
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}