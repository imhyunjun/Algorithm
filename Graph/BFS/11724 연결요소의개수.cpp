#include <iostream>

using namespace std;

int N, M;
int graph[1001][1001];
int visited[1001];
int connectionCount = 0;

void DFS(int _v)
{
	visited[_v] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && graph[_v][i])
		{
			//cout << "v: " << _v << "i: " << i << endl;
			DFS(i);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			connectionCount++;
		}

	}

	cout << connectionCount;

	return 0;
}