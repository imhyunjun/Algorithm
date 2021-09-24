#include <iostream>
using namespace std;

bool divide[1000001];

int main()
{
	int m, M;
	int cnt = 0;
	cin >> m >> M;

	for (int i = 2; i * i <= M; i++) 
	{
		int sqr = i * i;
		int q = m / sqr;
		int r = m % sqr;
		int start = 0;

		if (r != 0)
		{
			start = (q + 1) * sqr;
		}
		else
			start = m;

		for (int j = 0; start + sqr * j <= M; j++)
		{
			if (!divide[sqr * j])
			{
				cout << sqr * j << "\n";
				divide[sqr * j] = true;
				cnt++;
			}
		}
		
	}

	cout << M - m + 1 - cnt;

	return 0;
}