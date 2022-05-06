#include <iostream>

using namespace std;

int N;

int a[20][20];
int v[20][20];
int total = 0;
int minV = 500;
int sum = 0;

void DFS(int _n)
{
	if (_n == N / 2)
	{
		int l = total - sum;
		if (abs(sum - l) < minV)
		{
			minV = abs(sum - l);
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!v[i][j])
				{
					v[i][j] = true;
					v[j][i] = true;
					sum = sum + (a[i][j] + a[j][i]);
					DFS(_n + 1);
					sum = sum - (a[i][j] + a[j][i]);
					v[i][j] = false;
					v[j][i] = false;

				}
			}
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
			total += a[i][j];
		}
	}

	DFS(0);

	cout << minV;

	return 0;
}