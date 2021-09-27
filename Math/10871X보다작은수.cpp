#include <iostream>

using namespace std;

int main()
{
	int N, X;

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		int y;
		cin >> y;
		if (y < X)
		{
			cout << y << " ";
		}
	}

	return 0;
}