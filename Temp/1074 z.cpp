#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, r, c;
	cin >> N >> r >> c;
	r++; c++;
	int order = 0;

	while (N > 0)
	{
		int num = pow(2, N);
		int halfx = num / 2;
		int halfy = num / 2;
		int quater = num * num / 4;

		//4µîºÐ

		if (c <= halfx && r <= halfy)
		{

		}
		else if (c > halfx && r <= halfy)
		{
			order += quater;
			c -= halfx;
		}
		else if (c <= halfx && r > halfy)
		{
			order += quater * 2;
			r -= halfy;
		}
		else
		{
			order += quater * 3;
			c -= halfx;
			r -= halfy;
		}

		N--;
	}

	cout << order;

	return 0;
}