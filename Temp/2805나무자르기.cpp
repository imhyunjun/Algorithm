#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> trees;

bool Comp(int _a, int _b)
{
	return _a > _b;
}

int VectorSum(int _minus)
{
	int sum = 0;

	for (int i = 0; i < trees.size(); i++)
	{
		int temp = trees[i] - _minus;
		if (temp <= 0) temp = 0;
		sum += temp;
	}

	return sum;
}

int BS()
{
	int temp = N - 1;
	int high = trees[0];	
	int low = trees[temp];

	while (true)
	{
		int average = (high + low) / 2;

		int m = VectorSum(average);

		if (m == M)
		{
			return average;
		}
		else if (m < M)
		{
			high = average;
			if (high == low)
			{
				while (m >= M)
				{
					high--;
					low--;
					m = VectorSum(high);
				}
				return high;
			}
		}
		else
		{
			low = average;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		trees.push_back(x);
	}

	sort(trees.begin(), trees.end(), Comp);

	cout << BS();

	return 0;
}