#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	int N;	//회의의 수

	cin >> N;

	vector<pair<int, int>> times;
	times.resize(N);

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		times[i] = make_pair(x, y);
	}

	sort(times.begin(), times.end(), Comp);

	int current_end_time = 0;
	int count = 0;

	for (auto time : times)
	{
		if (time.first >= current_end_time)
		{
			count++;
			current_end_time = time.second;
		}
		else
		{
			continue;
		}
	}


	cout << count;

	return 0;
}