#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//정방향
vector<vector<int>> g;
//역방향
vector<vector<int>> ig;
vector<vector<int>> scc;
stack<int> st;
int visited[10001];

int V, E;
int cnt = 0;

void DFS(int _v)
{
	visited[_v] = 1;
	for (auto v : g[_v])
	{
		if (!visited[v])
		{
			DFS(v);
		}
	}

	st.push(_v);
}

void R_DFS(int _v, vector<vector<int>>& scc)
{
	visited[_v] = 1;
	scc[cnt].push_back(_v);
	for (auto v : ig[_v])
	{
		if(!visited[v])
			R_DFS(v, scc);
	}
}

int main()
{
	cin >> V >> E;

	g.resize(10001);
	ig.resize(10001);
	scc.resize(10001);

	for (int i = 1; i <= E; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		ig[y].push_back(x);
	}

	for (int i = 1; i <= V; i++)
	{
		if (!visited[i])
		{
			DFS(i);
		}
	}

	memset(visited, 0, sizeof(visited));

	while (!st.empty())
	{
		int s = st.top();
		st.pop();
		if (!visited[s])
		{
			R_DFS(s, scc);
			cnt++;
		}
	}

	cout << cnt << "\n";
	scc.resize(cnt);

	for (int i = 0; i < cnt; i++)
	{
		sort(scc[i].begin(), scc[i].end());
	}

	sort(scc.begin(), scc.end());

	for (int i = 0; i < cnt; i++)
	{
		for (int v : scc[i])
			cout << v << ' ';

		cout << "-1" << "\n";
	}

	return 0;
}