#include <iostream>
#include <algorithm>

using namespace std;

bool Pythagoras(int _a, int _b, int _c)
{
	return _c * _c == _a * _a + _b * _b;
}

int main()
{
	while (true)
	{
		int a[3];
		for (int i = 0; i < 3; i++)
		{
			cin >> a[i];
		}

		if (a[1] == 0) break;

		sort(a, a + 3);

		if (Pythagoras(a[0], a[1], a[2]))
		{
			cout << "right";
		}
		else
			cout << "wrong";
	
	}
	return 0;
}