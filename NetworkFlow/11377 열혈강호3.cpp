#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int capacity[2005][2005];
int flow[2005][2005];
vector<int> adj[2005];

int N, M, K;

int main()
{
	cin >> N >> M >> K;
	//0 : 소스
	//1 : K정점
	//2 : 싱크

	adj[0].push_back(1);
	adj[1].push_back(0);
	capacity[0][1] = K;
	
	for (int i = 3; i < N + 3; i++)
	{
		int works;
		cin >> works;
		adj[0].push_back(i);
		adj[i].push_back(0);
		adj[1].push_back(i);
		adj[i].push_back(1);
		capacity[0][i] = 1;
		capacity[1][i] = 1;

		for (int j = 0; j < works; j++)
		{
			int cnt;
			cin >> cnt;
			adj[i].push_back(2 + N + cnt);
			adj[2 + N + cnt].push_back(i);
			capacity[i][2 + N + cnt] = 1;
		}
	}

	for (int i = N + 3; i < 3 + N + M; i++)
	{
		adj[i].push_back(2);
		adj[2].push_back(i);
		capacity[i][2] = 1;
	}

	int total = 0;

	while (true)
	{
		vector<int> prev(2005, -1);
		queue<int> q;
		q.push(0);
		prev[0] = 0;

		while (!q.empty() && prev[2] == -1)
		{
			int curr = q.front();
			q.pop();

			for (int i = 0; i < adj[curr].size(); i++)
			{
				int next = adj[curr][i];
				int residual = capacity[curr][next] - flow[curr][next];
				if (residual > 0 && prev[next] == -1)
				{
					prev[next] = curr;
					q.push(next);
					//if (next == 2) break;
				}
			}
		}

		if (prev[2] == -1) break;

		int amount = 10000000;
		for (int i = 2; i != 0; i = prev[i])
		{
			amount = min(amount, capacity[prev[i]][i] - flow[prev[i]][i]);
		}
		for (int i = 2; i != 0; i = prev[i])
		{
			flow[prev[i]][i] += amount;
			flow[i][prev[i]] -= amount;
		}

		total += amount;
	}

	cout << total;

	return 0;
}
