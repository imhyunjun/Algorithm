#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;

	cin >> x; cout << endl;
	cin >> y;

	if (x * y > 0)
	{
		if (x > 0)
			cout << 1;
		else
			cout << 3;
	}
	else
	{
		if (x > 0)
			cout << 4;
		else
			cout << 2;
	}

	return 0;
}