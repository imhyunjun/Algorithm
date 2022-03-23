#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<long long> line;

int main()
{
	cin >> K >> N;

	line.resize(K);

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
	}

	sort(line.begin(), line.end(), greater<int>());

	long long min = 1;
	long long max = line[0];
	long long divisor = 1;
	int cnt = 0;
	long long answer = 0;

	while (true)
	{
		cnt = 0;
		divisor = min + (max - min) / 2;

		for (int i = 0; i < K; i++)
		{
			cnt += line[i] / divisor;
		}

		if (cnt >= N)
		{		
			min = divisor + 1;
			if (divisor > answer)
				answer = divisor;
		}
		else
		{
			max = divisor - 1;
		}

		if (min > max)
		{
			break;
		}
	}

	cout << answer;

	return 0;
}