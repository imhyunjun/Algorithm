#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	int sum = 0;
	int max = 0;

	vector<int> card;

	cin >> N >> M;

	card.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum <= M && sum > max) max = sum;
			}
		}
	}

	cout << max;
	
	return 0;
}