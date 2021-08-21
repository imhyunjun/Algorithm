#include <stdio.h>
#include <queue>

using namespace std;

int T;
int M, N, K;
int graph[50][50];
int visited[50][50];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0;
int c[50];

void BFS(int _x, int _y)
{
	queue<pair<int, int>> q;

	q.push(make_pair(_x, _y));

	visited[_x][_y] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < M && 0 <= ny && ny < N)
			{
				if (graph[nx][ny] == 1 && visited[nx][ny] == 0)
				{
					visited[nx][ny] = 1;

					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}


int main()
{
	scanf_s("%d\n", &T);

	for (int k = 0; k < T; k++)
	{
		memset(visited, 0, sizeof(visited));

		scanf_s("%d %d %d", &M, &N, &K);
		cnt = 0;

		for (int i = 0; i < K; i++)
		{
			int a, b;
			scanf_s("%d %d", &a, &b);
			graph[a][b] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0 && graph[i][j] == 1)
				{
					cnt++;
					BFS(i, j);
				}
			}
		}

		printf("%d", cnt);
	}

	return 0;
}