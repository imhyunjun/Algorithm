#include <iostream>
#include <vector>
using namespace std;

int N;
int parent[100001];
int visitied[100001];
vector<int> tree[1000001];

void SetParent(int _a)
{
	visitied[_a] = true;

	for (int i = 0; i < tree[_a].size(); i++)
	{
		int next = tree[_a][i];

		if (visitied[next] == 0)
		{
			parent[next] = _a;
			SetParent(next);
		}
	}
}

int main()
{
	std::cin >> N;

	int a, b;

	parent[1] = -1;		//1만 따로 설정

	for (int i = 0; i < N - 1; i++)
	{
		std::cin >> a >> b;
		
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	SetParent(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << endl;
	}
	return 0;
}