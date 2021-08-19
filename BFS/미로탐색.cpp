// ���� ��� ���� �Ÿ��� ����� ������ Ž��

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int check[101][101];
int visit[101][101];
char map[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int _x, int _y)
{
	visit[_x][_y] = 1;			//�湮
	queue<pair<int, int>> q;
	q.push(make_pair(_x, _y));


	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) // �̷��� ����
			{
				// ���� �����ϰ� ������ �湮�ߴ����� ���� ���
				if (map[next_x][next_y] == '1' && visit[next_x][next_y] == 0)
				{
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y)); // ť�� ������ �о�ֱ�
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string num;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		for (int j = 0; j < M; j++)
		{
			map[i][j] = num[j];
		}
	}

	BFS(0, 0);

	cout << check[N - 1][M - 1] + 1;

	return 0;
}