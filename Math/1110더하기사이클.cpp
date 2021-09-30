#include <iostream>
using namespace std;

int cnt = 0;

int Cycle(int _n)
{
	/*if (_n < 10)
	{
		_n = _n * 10;
	}*/

	int q = _n / 10;
	int r = _n % 10;

	int temp = q + r;
	int newN = r * 10 + temp % 10;
	cout << newN << endl;
	
	return newN;
}


int main()
{
	while (true)
	{
		int N;
		cin >> N;

		int oldN = N;

		while (true)
		{
			int newN = Cycle(oldN);
			cnt++;

			if (newN == N) break;

			oldN = newN;
		}
		cout << cnt << endl;
	}

	return 0;
}