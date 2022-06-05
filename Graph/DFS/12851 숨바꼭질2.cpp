#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int minV;
int c;
bool visited[100001];

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

void Soln(int _n, int _k)
{
	//cin >> N >> K;
	N = _n;
	K = _k;

	minV = abs(K - N) + 1;
	memset(visited, 0, sizeof(visited));
	Find();

	cout << "min value : " << minV << "\n" << "개수 : " << c << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int i, j;
	cin >> i >> j;
	cin.clear();

	Soln(i, j);

	/*for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 100000; j++)
		{
			Soln(i, j);
			cout << "{i, j} : " << i << "," << j << "\n";
		}
	}*/

	fflush(stdout);
	cout << fflush;
	return 0;
}