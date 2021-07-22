#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H;
	int M = 0;
	cin >> H >> M;

	M -= 45;

	if (M < 0)
	{
		H--;
		if (H < 0)
			H += 24;
		M += 60;
	}

	cout << H << M << endl;
	return 0;
}