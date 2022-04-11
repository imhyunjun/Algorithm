#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double D, H, W;

	cin >> D >> H >> W;

	double asquare = D * D / (H * H + W * W);
	double a = sqrt(asquare);

	cout << floor(H * a) << " " << floor(W * a);

	return 0;
}