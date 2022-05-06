#include <iostream>

using namespace std;

int N, M;
int v[9];
int a[9];

void DFS(int _n)
{
	if (_n == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << a[i] << ' ';
		}

		cout << "\n";
	}
	else
	{
		int t = 0;
		if (_n == 0) t = 1;
		else if (_n > 0) t = a[_n - 1];

		for (int i = t; i <= N; i++)
		{
			if (!v[i])
			{
				v[i] = true;
				a[_n] = i;
				DFS(_n + 1);
				v[i] = false;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	DFS(0);
	return 0;
}