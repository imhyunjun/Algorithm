#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int graph[1001][1001] = { 0, };
int DFSvisited[1001];
int cnt = 0;

void DFS(int _v)
{
	DFSvisited[_v] = 1;
	cnt++;
	cout << _v << ' ';
	if (cnt == N)
	{
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!DFSvisited[i] && graph[_v][i])
		{
			DFS(i);
		}
	}
}

void BFS()
{
	int visited[1001] = { 0, };
	queue<int> q;

	q.push(V);
	visited[V] = 1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << ' ';
		for (int i = 1; i < N + 1; i++)
		{
			if (!visited[i] && graph[curr][i])
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main()
{

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;

		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	DFS(V);
	cout << '\n';
	BFS();

	return 0;


}
