#include <iostream>
#include <vector>

using namespace std;

vector<int> money;

int Count(int _k)
{
	int current = _k;
	int cnt = 1;

	for (vector<int>::iterator it = money.begin(); it != money.end(); it++)
	{
		if (current >= *it)
		{
			current -= *it;
		}
		else
		{
			current = _k;
			current -= *it;
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	int N, M;

	int mid = 0;
	int start = 0;
	int end = 0;
	int answer = 0;

	cin >> N >> M;
	money.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
		end += money[i];

		if (start < money[i]) start = money[i];
	}

	while (true)
	{
		if (start > end) break;

		mid = (start + end) / 2;

		if (Count(mid) > M)
		{
			start = mid + 1;
		}
		else
		{
			answer = mid;
			end = mid - 1;
		}
	}

	cout << answer;

	return 0;
}