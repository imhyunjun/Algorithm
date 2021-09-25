#include <iostream>

using namespace std;

int main()
{
	int N, L;

	cin >> N >> L;

	while (true)
	{
		int d = N - (L - 1) * L / 2;

		if (d < L && d != 0)
		{
			cout << -1;
			break;
		}

		if (d % L == 0)
		{
			for (int i = 0; i < L; i++)
			{
				cout << d / L + i << " ";
			}
			break;
		}

		L++;

		if (L > 100)
		{
			cout << -1;
			break;
		}
	}

	return 0;
}