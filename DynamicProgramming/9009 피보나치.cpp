#include <iostream>
#include <stack>

using namespace std;

#define ull unsigned long long

ull dp[100000];
ull num;

ull Fib(int _maxNum)
{
	int idx = 2;

	while (true)
	{
		dp[idx] = dp[idx - 2] + dp[idx - 1];
		num = dp[idx];

		if (num > _maxNum)
		{
			while (dp[idx] > _maxNum)
			{
				idx--;
				num = dp[idx];
			}

			break;
		}
		idx++;
	}

	return num;
}

int main()
{
	int T;
	cin >> T;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		stack<ull> s;

		while (n > 0)
		{
			int f = Fib(n);
			n -= f;
			s.push(f);
		}

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << "\n";
	}
	return 0;
}