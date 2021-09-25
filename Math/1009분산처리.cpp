#include <iostream>
#include <cmath>
using namespace std;


int Pow(int _a, int _b)
{
	int ans = 1;

	for (int i = 0; i < _b; i++)
	{
		ans *= _a;
		ans %= 10;

		if (ans == 0)
		{
			return 10;
		}
	}

	return ans;
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		long long a, b;
		cin >> a >> b;

		cout << Pow(a, b) << "\n";
	}

	return 0;
}