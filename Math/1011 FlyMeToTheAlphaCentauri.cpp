#include <iostream>

using namespace std;

int T, x, y;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		int length = y - x;
		int cnt = 0;
		int j = 1;

		while (length > 0)
		{
			if (length == j)
			{
				cnt++;
				length -= j;
			}
			else if (2 * (j - 1) <= length && length <= 2 * j)
			{
				cnt += 2;
				length = 0;
			}
			else if(length > 2 * j)
			{
				cnt += 2;
				length -= 2 * j;				
			}
			else
			{
				length += 2 * (j + 1);
				cnt -= 2;
				j -= 3;
			}

			j++;
		}

		cout << cnt << "\n";
	}
	return 0;
}