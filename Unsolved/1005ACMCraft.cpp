#include <iostream>
#include <vector>
using namespace std;

int T, N, K, W;
vector<int> times;
vector<pair<int, int>> order;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		for (int j = 0; j < N; j++)
		{
			int time;
			cin >> time;
			times.push_back(time);
		}

		for (int k = 0; k < K; k++)
		{
			int first, second;
			cin >> first >> second;
			order.push_back(make_pair(first, second));
		}
	}


	return 0;
}