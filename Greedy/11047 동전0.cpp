#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int K;
	int sum = 0;
	cin >> N >> K;

	vector<int> coins;
	coins.resize(N);

	for(int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	reverse(coins.begin(), coins.end());

	for (int i : coins)
	{
		int quotient = K / i;
		int remainder = K % i;

		K = remainder;
		sum += quotient;
		if (K == 0) break;
	}

	cout << sum;

	return 0;
}