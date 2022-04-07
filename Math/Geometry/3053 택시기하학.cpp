#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float R;
	cin >> R;

	cout << fixed;
	cout.precision(6);

	cout << pow(R, 2) * M_PI << "\n";
	cout << pow(R, 2) * 2;

	return 0;
}