#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

pair<int, int> points[100000];
set<pair<int, int>> s;

int GetDist(pair<int, int> _a, pair<int, int> _b)
{
	return pow(_a.first - _b.first, 2) + pow(_a.second - _b.second, 2);
}

bool Comp(pair<int, int> _a, pair<int, int> _b)
{
	if (_a.first == _b.first) return _a.second < _b.second;

	return _a.first < _b.first;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> points[i].first >> points[i].second;
	}

	sort(points, points + n, Comp);
	s.insert({ points[0].second, points[0].first });
	s.insert({ points[1].second, points[1].first });

	int min = GetDist(points[0], points[1]);
	int j = 0;
	for (int i = 2; i < n; i++)
	{
		while (j < i)
		{
			if (pow(points[j].first - points[i].first, 2) > min)
			{
				s.erase({ points[j].second, points[j].first });
				j++;
			}
			break;
		}

		auto start = s.lower_bound({points[i].second - sqrt(min),  -INFINITY});
		auto end = s.upper_bound({points[i].second + sqrt(min), INFINITY});

		for (auto it = start; it != end; it++)
		{
			min = std::min(min, GetDist(points[i], { it->second, it->first }));
		}
		s.insert({ points[i].second, points[i].first });
	}

	cout << min;

	return 0;
}