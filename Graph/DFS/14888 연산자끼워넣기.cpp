#include <iostream>

using namespace std;

int N;
int seq[11];
int op[4];	//µ¡¼À, »¬¼À °ö¼À ³ª´°¼À
int minV = 1000000001;
int maxV =  -1000000001;

void DFS(int _n, int _r)
{
	if (_n == N)
	{
		if (_r < minV)
		{
			minV = _r;
		}
		if (_r > maxV)
		{
			maxV = _r;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] > 0)
		{
			op[i]--;
			int nextr = 0;
			switch (i)
			{
			case 0:
				nextr = _r + seq[_n];
				break;
			case 1:
				nextr = _r - seq[_n];
				break;
			case 2:
				nextr = _r * seq[_n];
				break;
			case 3:
				nextr = _r / seq[_n];
				break;
			default:
				break;
			}

			DFS(_n + 1, nextr);
			op[i]++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	DFS(1, seq[0]);

	cout << maxV << "\n" << minV;

	return 0;
}