#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, double>> points;


double GetArea(pair<double, double> _a, pair<double, double> _b, pair<double, double> _c)
{
	return ((_a.first - _b.first) * (_a.second - _c.second) - (_a.first - _c.first) * (_a.second - _b.second)) / 2;
}

int main()
{
	int N;
	cin >> N;
	points.resize(N);

	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		points[i] = { x, y };
	}
	double area = 0;
	for (int i = 1; i < N - 1; i++)
	{
		area += GetArea(points[0], points[i], points[long(i + 1)]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(area);
	return 0;
}