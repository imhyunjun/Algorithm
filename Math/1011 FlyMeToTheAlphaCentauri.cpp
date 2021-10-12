#include <iostream>
#include <cmath>

using namespace std;

int T, x, y;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;

		int length = y - x;
		int j = floor(sqrt(length));

		int sqr = j * j;
		int term = length - sqr;
		int cnt = 2 * j - 1;

		if (term != 0)
		{
			term--;
			int quotient = term / j;

			cnt += quotient + 1;
		}

		cout << cnt << "\n";
	}
	return 0;
}