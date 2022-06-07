#include <iostream>
#include <vector>

using namespace std;

short N, M;

//vector<vector<short>> laptops;
//vector<bool> visited;
//vector<short> partner;

bool visited[5001];				//1 * 5001 = 5001
short partner[5001];			//2 * 5001 = 10002
vector<short> laptops[101];		//¾à 2 * 101 = 202

bool DFS(int _n)
{
	for (short i = 0; i < laptops[_n].size(); i++)
	{
		short laptopIdx = laptops[_n][i];
		if (visited[laptopIdx]) continue;
		visited[laptopIdx] = true;

		if (partner[laptopIdx] == 0 || DFS(partner[laptopIdx]))
		{
			partner[laptopIdx] = _n;
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> N >> M;
	//laptops.resize(N + 1);
	//visited.resize(M + 1);
	//partner.resize(M + 1);

	for (int i = 0; i < M; i++)
	{
		short a, b;
		cin >> a >> b;
		laptops[a].push_back(b);
	}

	short cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		//visited.assign(M + 1, 0);
		memset(visited, false, sizeof(visited));
		if (DFS(i))
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}