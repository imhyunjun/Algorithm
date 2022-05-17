#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 알파벳 -> 숫자 변환
int CtoI(char c) {
	// index: 대문자 = 0~25 , 소문자 = 26~51
	if (c <= 'Z') return c - 'A'; // 대문자가 소문자보다 아스키 코드 작다.
	return c - 'a' + 26;
}

int c[52][52];
int f[52][52];
int visited[52];
vector<int> edge[52];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char s, e;
		int u, v, w;
		cin >> s >> e >> w;

		u = CtoI(s);
		v = CtoI(e);

		c[u][v] += w;
		c[v][u] += w;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	int total = 0;
	int S = CtoI('A');
	int E = CtoI('Z');

	//BFS
	while (true)
	{
		fill(visited, visited + 52, -1);
		queue<int> q;
		q.push(S);

		while (!q.empty() && visited[E] == -1)
		{
			int curr = q.front();
			q.pop();
			for (int n : edge[curr])
			{
				if (c[curr][n] - f[curr][n] > 0 && visited[n] == -1)
				{
					q.push(n);
					visited[n] = curr;
					if (n == E) break;
				}
			}
		}

		if (visited[E] == -1) break;
		int F = 1000000000;
		for (int i = E; i != S; i = visited[i])
		{
			F = min(F, c[visited[i]][i] - f[visited[i]][i]);
		}

		for (int i = E; i != S; i = visited[i]) {
			f[visited[i]][i] += F;
			f[i][visited[i]] -= F;
		}

		total += F;
	}

	cout << total;

	return 0;
}