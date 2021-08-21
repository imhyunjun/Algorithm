#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int graph[101][101];
int visited[101];
int cnt = 0;

void BFS()
{
	queue<int> q;
	q.push(1);		//1번 컴퓨터
	visited[1] = 1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 1; i < N + 1; i++)
		{
			if (graph[curr][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				q.push(i);
				cnt++;

				if (cnt > M) break;
			}
		}

		if (cnt > M) break;
	}
}


int main()
{
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf_s("%d %d", &a, &b);

		graph[a][b] = 1;		//연결되어있으면 1
		graph[b][a] = 1;
	}

	BFS();

	printf("%d", cnt);

	return 0;
}