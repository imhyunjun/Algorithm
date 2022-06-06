#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> work;
vector<vector<int>> work2;

int partner[1001];
int partner2[1001];
bool visited[1001];

bool DFS(int _n)
{
	for (int i = 0; i < work[_n].size(); i++)
	{
		int w = work[_n][i];
		if (visited[w]) continue;
		visited[w] = true;

		if (partner[w] == 0 || DFS(partner[w]))
		{
			partner[w] = _n;
			partner2[_n] = w;
			return true;
		}

	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	work.resize(2 * N + 1);

	for (int i = 1; i <= N; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int workNum;
			cin >> workNum;
			work[i].push_back(workNum);
			work[N + i].push_back(workNum);
		}
		
	}
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++)
	{
		if (partner2[i] == 0)
		{
			memset(visited, false, sizeof(visited));
			if (DFS(i)) cnt++;
		}
	}
	cout << cnt;
	return 0;
}