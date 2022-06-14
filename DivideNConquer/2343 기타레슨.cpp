#include <iostream>
#include <vector>

using namespace std;

vector<int> blueray;

int Count(int _k)
{
	int current = _k;
	int cnt = 1;

	for (vector<int>::iterator it = blueray.begin(); it != blueray.end(); it++)
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
	blueray.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> blueray[i];
		end += blueray[i];

		if (start < blueray[i]) start = blueray[i];	
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