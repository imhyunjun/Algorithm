#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}

	return a.first < b.first;
}

int table[101][100001];

int main()
{
	int N, K;
	vector<pair<int, int>> bag;		// 무게, 가치

	cin >> N >> K;
	bag.resize(N);

	for (int i = 0; i < N; i++)
	{
		int W, V;
		cin >> W >> V;

		bag[i] = { W, V };
	}

	//무게는 오름차순, 가치는 내림차순으로 정렬
	sort(bag.begin(), bag.end(), Comp);

	//1개부터 N개까지 하나씩
	for (int i = 1; i <= N; i++)
	{
		// 가능한 가장 작은 무게부터 최대 무게 까지
		for (int j = (*bag.begin()).first; j <= K; j++)
		{
			int weight = bag[i - 1].first;
			int value = bag[i - 1].second;

			if (weight > j)
			{
				table[i][j] = table[i - 1][j];
			}
			else
			{
				int val1 = table[i - 1][j - weight] + value;
				int val2 = table[i - 1][j];

				table[i][j] = max(val1, val2);
			}
		}
	}

	cout << table[N][K];

	return 0;
}