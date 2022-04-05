#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string f;
	string s;
	vector<vector<int>> dp;

	cin >> f >> s;

	dp.resize(s.size() + 1);

	for (int i = 0; i < dp.size(); i++)
	{
		dp[i].resize(f.size() + 1);
	}


	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 1; j <= f.size(); j++)
		{
			if (s[i - 1] == f[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[s.size()][f.size()];

	return 0;
}