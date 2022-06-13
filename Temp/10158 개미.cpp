#include <iostream>

using namespace std;

int main()
{
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	int tx = t + p;
	int ty = t + q;

	tx = tx % (2 * w);
	ty = ty % (2 * h);

	if (tx > w)
	{
		tx = w - (tx - w);
	}

	if (ty > h)
	{
		ty = h - (ty - h);
	}

	cout << tx << " " << ty;

	return 0;
}