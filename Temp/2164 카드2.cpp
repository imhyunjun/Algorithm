#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{

	int N;
	cin >> N;
	int last = 0;

	if (N % 2 == 0)
	{
		float l2 = log2(N);
		int c = (int)ceil(l2);
		int temp2 = pow(2, c);
		if (temp2 == N)
		{
			last = N;
		}
		else
		{
			last = 2 * (N - temp2 / 2);
		}
	}
	else if (N == 1) last = 1;
	else
	{
		int temp = N - 1;
		float l2 = log2(temp);
		int c = (int)ceil(l2);
		int temp2 = pow(2, c);
		if (temp2 == temp)
		{
			last = 2;
		}
		else
		{
			last = 2 + 2 * (temp - temp2 / 2);
		}

	}

	cout << last;

	return 0;
}