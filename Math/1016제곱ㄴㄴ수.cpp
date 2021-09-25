#include <iostream>
using namespace std;

bool divide[1000001];

int main()
{
	long long m, M;
	int cnt = 0;
	cin >> m >> M;

	for (long long i = 2; i * i <= M; i++) 
	{
		long long sqr = i * i;
		long long q = m / sqr;
		long long r = m % sqr;

		if (r != 0)
		{
			q++;
		}

		while (q * sqr <= M)
		{
			long long temp = q * sqr - m;
			divide[temp] = true;
			q++;
		}
		
	}

	for (int i = 0; i <= M - m; i++)
	{
		if (!divide[i]) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}