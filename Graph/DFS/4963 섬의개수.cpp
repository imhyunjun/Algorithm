#include <iostream>
#include <memory.h>

using namespace std;

int graph[51][51];
int visited[51][51];
int dr[] = { 1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = { 0, 0, 1, -1, 1, -1, 1, -1};
int w, h;

void DFS(int _r, int _c)
{
	visited[_r][_c] = 1;

	for (int i = 0; i < 8; i++)
	{
		int nextR = _r + dr[i];
		int nextC = _c + dc[i];

		//지도 범위 안
		if (0 < nextR && nextR <= h && 0 < nextC && nextC <= w)
		{
			if (!visited[nextR][nextC] && graph[nextR][nextC])
			{
				DFS(nextR, nextC);
			}
		}
	}
}

int main()
{

	int cnt;

	while (true)
	{
		cin >> w >> h;
		cnt = 0;
		memset(visited, 0, sizeof(visited));

		if (w + h == 0)
		{
			break;
		}

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> graph[i][j];
			}
		}

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (!visited[i][j] && graph[i][j])
				{
					DFS(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}