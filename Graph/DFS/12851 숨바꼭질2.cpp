#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int minV;
int c;
vector<bool> visited;

vector<int> FindNext1(int _n)
{
	int next = _n + 1;
	int prev = _n - 1;
	int twice = 2 * N;

	vector<int> newVec = { next, prev, twice };
	return newVec;
}

void Find()
{
	if (N == K)
	{
		minV = 0;
		c = 1;
		return;
	}

	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	pair<int, int> nextN;

	while (!q.empty())
	{
		nextN = q.front();
		if (nextN.second > minV) break;
		N = nextN.first;
		
		visited[N] = 1;
		
		q.pop();

		if (N >= K)
		{
			int time = nextN.second += (N - K);

			if (time < minV)
			{
				minV = time;
				c = 1;
			}
			else if (time == minV)
			{
				c++;
			}
		}
		else
		{
			vector<int> v = FindNext1(N);
			for (int i = 0; i < v.size(); i++)
			{
				//순서 중요
				if (v[i] >= 0 && !visited[v[i]])
				{
					q.push(make_pair(v[i], nextN.second + 1));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	minV = abs(K - N) + 1;
	visited.resize(2 * K + 1);

	Find();

	cout << minV << "\n";
	cout << c;

	return 0;
}