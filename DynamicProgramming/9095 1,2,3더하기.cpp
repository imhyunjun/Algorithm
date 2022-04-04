#include <iostream>

using namespace std;

int dp[12];

int Sum(int _n)
{
	if (dp[_n] > 0) return dp[_n];

	if (_n == 1)
	{
		dp[_n] = 1;
		return 1;
	}

	if (_n == 2)
	{
		dp[_n] = 2;
		return 2;
	}

	if (_n == 3)
	{
		dp[_n] = 4;
		return 4;
	}

	return dp[_n] = Sum(_n - 1) + Sum(_n - 2) + Sum(_n - 3);
}

int main()
{
	int T, N;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		cout << Sum(N) << "\n";
	}

	return 0;
}