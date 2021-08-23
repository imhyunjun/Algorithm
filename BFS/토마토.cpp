#include <stdio.h>
#include <queue>

using namespace std;

#define Max 1000

int M, N;
int graph[Max][Max];
int visited[Max][Max];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

int day = 0;
int vacant = 0;			//빈 토마도 갯수
int cnt = 0;			//1이 된 토마도 개수

void BFS()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		visited[x][y] = 1;

		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			int curr = graph[x][y];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (visited[nx][ny] == 0 && graph[nx][ny] == 0)
				{
					visited[nx][ny] = 1;
					graph[nx][ny] = curr + 1;
					day = curr + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}


int main()
{
	scanf_s("%d %d\n", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &graph[i][j]);

			if (graph[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
			else if (graph[i][j] == -1)
			{
				vacant++;
			}
		}
	}

	BFS();

	printf("%d\n", cnt);
	printf("%d\n", day);
	printf("%d\n", vacant);

	int temp = vacant + cnt;

	if (temp < M * N) printf("%d\n", -1);		//0인게 존재

	else if (temp == M * N)
	{
		printf("%d\n", day);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", graph[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", visited[i][j]);
		}

		printf("\n");
	}

	return 0;
}