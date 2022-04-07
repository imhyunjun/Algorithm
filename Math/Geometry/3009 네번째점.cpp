#include <iostream>
#include <map>

using namespace std;

map<int, int> coordX;
map<int, int> coordY;
int X[3];
int Y[3];

int main()
{
	int aX, aY = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> X[i] >> Y[i];

		coordX[X[i]]++;
		coordY[Y[i]]++;
	}

	for (int i = 0; i < 3; i++)
	{
		if (coordX[X[i]] % 2 == 1)
		{
			aX = X[i];
		}

		if (coordY[Y[i]] % 2 == 1)
		{
			aY = Y[i];
		}
	}

	cout << aX << " " << aY;

	return 0;
}