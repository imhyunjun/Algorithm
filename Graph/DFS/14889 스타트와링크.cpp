#include <iostream>

using namespace std;

int N;

int a[20][20];
int v[20];
int minV = 500;
int sum1 = 0;
int sum2 = 0;

void DFS(int _n, int _p)
{
	if (_n == (N / 2))
	{
		sum1 = 0;
		sum2 = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{

				if (v[i] && v[j])
				{
					sum1 += a[i][j];
					sum1 += a[j][i];
				}
				else if (!v[i] && !v[j])
				{
					sum2 += a[i][j];
					sum2 += a[j][i];
				}
			}
		}
		
		if (abs(sum1 - sum2) < minV)
		{
			minV = abs(sum1 - sum2);
		}
	}
	else
	{
		for (int i = _p; i < N; i++)
		{
			v[i] = 1;
			DFS(_n + 1, i);
			v[i] = 0;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}

	DFS(0, 0);

	cout << minV;

	return 0;
}