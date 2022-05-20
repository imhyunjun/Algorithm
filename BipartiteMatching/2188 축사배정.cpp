#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> barn[201];
bool visited[201];
int partner[201];
int cnt = 0;

bool DFS(int _n)
{
	for (int i = 0; i < barn[_n].size(); i++)
	{
		int p = barn[_n][i];
		if (visited[p])
		{
			continue;
		}
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
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			barn[i].push_back(num);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + 201, false);
		if (DFS(i)) cnt++;
	}

	cout << cnt;

	return 0;
}