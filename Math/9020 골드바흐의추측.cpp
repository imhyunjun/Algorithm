#include <iostream>

using namespace std;

int T;

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
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		int m1 = n / 2;
		int m2 = n - m1;

		while (!Prime(m1) || !Prime(m2))
		{
			m1--;
			m2++;

			if (m2 > n || m1 < 1) break;
		}

		cout << m1 << ' ' << m2 << "\n";

	}

	return 0;
}