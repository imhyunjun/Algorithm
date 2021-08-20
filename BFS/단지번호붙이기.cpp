#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
char graph[25][25] = { 0 };
int visited[26][26];
int home[626] = { 0, };
int num = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int _x, int _y)
{

	queue<pair<int, int>> q;

	q.push(make_pair(_x, _y));
	visited[_x][_y] = 1;

	home[num]++;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();



		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
			{
				if (graph[next_x][next_y] == '1' && visited[next_x][next_y] == 0)
				{
					visited[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y));

					home[num]++;
				}
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < N; j++)
		{
			graph[i][j] = temp[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0 && graph[i][j] == '1')
			{
				num++;
				BFS(i, j);
			}
		}
	}

	sort(home + 1, home + num + 1);

	cout << num << endl;

	for (int i = 1; i <= num; i++)
	{
		cout << home[i] << endl;
	}

	return 0;
}