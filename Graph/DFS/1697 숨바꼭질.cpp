#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int t;
int visited[100001];

vector<int> FindNext1(int _n)
{
	int newN1 = _n + 1;
	int newN2 = _n - 1;
	int newN3 = 2 * N;

	vector<int> newVec = { newN1, newN2, newN3 };
	return newVec;
}

void Find()
{
	if (N == K)
	{
		return;
	}

	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	pair<int, int> nextN;

	while (!q.empty())
	{
		nextN = q.front();
		N = nextN.first;
		visited[N] = 1;
		q.pop();

		if (N == K)
		{
			break;
		}
		else
		{
			vector<int> v = FindNext1(N);

			for (int i = 0; i < v.size(); i++)
			{
				//순서 중요
				if (v[i] >= 0  && v[i] <= 100000 && !visited[v[i]]) q.push(make_pair(v[i], nextN.second + 1));
			}
		}
	}

	t = nextN.second;
}

int main()
{
	cin >> N >> K;

	Find();

	cout << t;

	return 0;
}