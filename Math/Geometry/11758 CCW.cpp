#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int cross = (x1 - x2) * (y2 - y3) - (y1 - y2) * (x2 - x3);

	if (cross == 0) cout << 0;
	else if (cross > 0) cout << 1;
	else cout << -1;

	return 0;
}