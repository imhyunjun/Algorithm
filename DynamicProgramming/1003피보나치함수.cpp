#include <iostream>

using namespace std;

int num0, num1 = 0;
int dp[41] = { 1, 1, };
void Fib()
{
	for (int i = 2; i < 41; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main()
{
	Fib();

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			num0 = 1;
			num1 = 0;
		}
		else if (n == 1)
		{
			num0 = 0;
			num1 = 1;
		}
		else
		{
			num0 = dp[n - 2];
			num1 = dp[n - 1];
		}

		cout << num0 << " " << num1 << "\n";
	}

	return 0;
}