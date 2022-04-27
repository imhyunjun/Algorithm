#include <iostream>
#include <vector>
#include <queue>
#include <deque>

std::pair<int, int> Rotate(std::pair<int, int> _v, int _clock = 1)
{
	int x = -1 * _v.second * _clock;
	int y = 1 * _v.first * _clock;
	return { x, y };
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::vector<std::vector<int>> graph;
	std::deque<std::pair<int, int>> snake;
	std::queue<std::pair<int, char>> time;

	std::cin >> N >> K;

	graph.resize(N);
	for (int i = 0; i < N; i++)
	{
		graph[i].resize(N);
	}

	for (int i = 0; i < K; i++)
	{
		int x, y;
		std::cin >> x >> y;
	
		graph[x - 1][y - 1] = 2;
	}

	int L;
	std::cin >> L;

	for (int i = 0; i < L; i++)
	{
		int t;
		char x;
		std::cin >> t >> x;
		time.push({ t, x });
	}
	int playTime = 0;

	std::pair<int, int> pos = { 0, 0 };
	std::pair<int, int> dir = { 0, 1 };

	graph[0][0] = 1;
	snake.push_back(pos);

	while (true)
	{
		if (!time.empty())
		{
			int t = time.front().first;
			if (t == playTime)
			{
				if (time.front().second == 'L')
				{
					//왼쪽으로 회전
					dir = Rotate(dir);
				}
				else if (time.front().second == 'D')
				{
					//오른쪽으로 회전
					dir = Rotate(dir, -1);
				}

				time.pop();
			}
		}

		playTime++;
		int n_x = pos.first + dir.first;
		int n_y = pos.second + dir.second;
		pos = { n_x, n_y };
		snake.push_front({ n_x, n_y });


		if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= N || graph[n_x][n_y] == 1)
		{
			break;
		}
		
		if (graph[n_x][n_y] == 0)
		{
			int x = snake.back().first;
			int y = snake.back().second;
			snake.pop_back();
			graph[x][y] = 0;
		}

		graph[n_x][n_y] = 1;
	}

	std::cout << playTime;
	return 0;

}