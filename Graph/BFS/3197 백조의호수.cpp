#include <iostream>
#include <queue>

using namespace std;

int R, C;
char graph[1501][1501];
int visited[1501][1501];

int start[] = { 0, 0 };

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

queue<pair<int, int>> swanq;
queue<pair<int, int>> swannextq;
queue<pair<int, int>> waterlastq;
queue<pair<int, int>> waternextq;

int day = 0;
bool isMet = false;

//백조 혹은 물의 이동
void BFS()
{
	while (!swanq.empty() && !isMet)
	{
		pair<int, int> p = swanq.front();
		swanq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = p.first + dr[i];
			int nextC = p.second + dc[i];
			
			if (0 <= nextR && nextR < R && 0 <= nextC && nextC < C)
			{
				if (!visited[nextR][nextC])
				{
					visited[nextR][nextC] = 1;

					char next = graph[nextR][nextC];

					if (next == 'L') 
					{
						isMet = true;
						break;
					}
					else if (next == 'X')
					{
						swannextq.push({ nextR, nextC });
					}
					else
					{
						swanq.push({ nextR, nextC });
					}
				}
			}
		}
	}
}

//얼음의 변화
void Ice_BFS()
{
	while (!waterlastq.empty())
	{
		pair<int, int> p = waterlastq.front();

		waterlastq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = p.first + dr[i];
			int nextC = p.second + dc[i];
				
			if (0 <= nextR && nextR < R && 0 <= nextC && nextC < C)
			{
				char next = graph[nextR][nextC];

				if (next == 'X')
				{
					waternextq.push({ nextR, nextC });
					graph[nextR][nextC] = '.';
				}
			
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'L')
			{
				start[0] = i;
				start[1] = j;
			}
			if (graph[i][j] != 'X')
			{
				waterlastq.push({ i, j });
			}
		}
	}

	swanq.push({ start[0], start[1]});
	visited[start[0]][start[1]] = 1;

	while (!isMet)
	{
		BFS();
		if (isMet) break;
		else
		{
			Ice_BFS();
			day++;

			waterlastq = waternextq;
			swanq = swannextq;

			while (!waternextq.empty()) waternextq.pop();
			while (!swannextq.empty()) swannextq.pop();
		}
	}

	cout << day;

	return 0;
}