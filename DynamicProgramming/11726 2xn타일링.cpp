#include <iostream>

using namespace std;

int dp[1001];

int Tile(int _n)
{
	if (dp[_n] > 0) return dp[_n];

	if (_n == 1)
	{
		dp[_n] = 1;
		return 1;
	}
	else if (_n == 2)
	{
		dp[_n] = 2;
		return 2;
	}

	dp[_n] = (Tile(_n - 1) + Tile(_n - 2)) % 10007;
	return dp[_n];
}

int main()
{
	int n;
	cin >> n;

	cout << Tile(n);

	return 0;
}