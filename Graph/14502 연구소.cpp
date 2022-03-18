#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int graph[8][8];
int tempgraph[8][8];
int wall = 3;
int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };
int visited[8][8];
int maxSafety = 0;

queue<pair<int, int>> q;
queue<pair<int, int>> tempq;


int CountSafetyZone()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tempgraph[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void Spread()
{
	copy(&graph[0][0], &graph[0][0] + 64, &tempgraph[0][0]);
	tempq = q;

	while (!tempq.empty())
	{
		int r = tempq.front().first;
		int c = tempq.front().second;

		tempq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nR = r + dr[i];
			int nC = c + dc[i];

			if (0 <= nR && nR < N && 0 <= nC && nC < M)
			{
				if (tempgraph[nR][nC] == 0)
				{
					tempgraph[nR][nC] = 2;
					tempq.push({ nR, nC });
				}
			}
		}
	}


	int cnt = CountSafetyZone();

	if (cnt > maxSafety)
	{
		maxSafety = cnt;
	}

}

void BuildWall(int _cnt)
{
	if (_cnt == 3)
	{
		Spread();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0)
			{
				graph[i][j] = 1;
				BuildWall(_cnt + 1);
				graph[i][j] = 0;
			}
		}
	}
}



int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
				q.push({ i, j });
		}
	}

	BuildWall(0);

	cout << maxSafety;

	return 0;
}