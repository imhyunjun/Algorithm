#include <iostream>

using namespace std;

int N;
int graph[15];
int cnt = 0;

void Queen(int _cnt)
{
	if (_cnt == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		graph[_cnt] = i;

		bool b = true;
		for (int j = 0; j < _cnt; j++)
		{
			//같은 열인지
			if (graph[j] == i)
				b = false;

			//대각선인지
			if (abs(_cnt - j) == abs(graph[j] - i))
				b = false;
		}

		if (b)
			Queen(_cnt + 1);
	}
}

int main()
{
	cin >> N;
	Queen(0);
	cout << cnt;

	return 0;
}