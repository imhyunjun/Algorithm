#include <iostream>
#include <vector>
using namespace std;

int N, M;
int partner[1001];
vector<int> work[1001];
bool visited[1001];
int cnt = 0;

bool DFS(int _n)
{
	for (int i = 0; i < work[_n].size(); i++)
	{
		int p = work[_n][i];
		if (visited[p]) continue;
		visited[p] = true;

		if (partner[p] == 0 || DFS(partner[p]))
		{
			partner[p] = _n;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			int w;
			cin >> w;
			work[i].push_back(w);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + 1001, false);
		if (DFS(i)) cnt++;
	}

	cout << cnt;

	return 0;
}