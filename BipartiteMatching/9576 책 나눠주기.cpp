#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M;
int partner[1001];
bool visited[1001];
vector<pair<int, int>> book;

bool DFS(int _n)
{
	int a = book[_n].first;
	int b = book[_n].second;

	for (int i = a; i <= b; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;

		if (partner[i] == 0 || DFS(partner[i]))
		{
			partner[i] = _n;
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int cnt = 0;

		cin >> N >> M;

		book.clear();
		book.push_back({ 0, 0 });
		fill(partner, partner + 1001, 0);

		for (int j = 1; j <= M; j++)
		{
			int a, b;
			cin >> a >> b;
			book.push_back({ a, b });
		}

		for (int j = 1; j <= M; j++)
		{
			fill(visited, visited + 1001, false);
			if (DFS(j)) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}