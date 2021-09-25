#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> range;

int BS(int _v)
{
	int first = 0;
	int last = range.size() - 1;

	while (true)
	{
		int length = last - first;
		int mid_idx = first + length / 2;
		int mid = range[mid_idx];

		if (mid == _v) return 1;
		else if (mid < _v)
		{
			first = mid_idx;
		}
		else
		{
			last = mid_idx;
		}

		if (length == 1)
		{
			if (range[last] == _v || range[first] == _v) return 1;
			else return 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		range.push_back(x);
	}

	sort(range.begin(), range.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		cout << BS(x) << "\n";
	}


	return 0;
}