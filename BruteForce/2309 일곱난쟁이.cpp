#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int sum = 0;
	vector<int> heights;
	heights.resize(9);

	for (int i = 0; i < 9; i++)
	{
		cin >> heights[i];
		sum += heights[i];
	}

	sort(heights.begin(), heights.end());

	int left = sum - 100;

	vector<int>::iterator it;

	for (it = heights.begin(); it != heights.end(); it++)
	{
		if (*it >= left) continue;

		int sub = left - *it;

		if (sub > heights[8]) continue;

		auto i = find(it + 1, heights.end(), sub);

		if ( i != heights.end())
		{
			*i = -1;
			*it = -1;
			break;		//처음에 break 안했다가 반례 10 10 10 10 10 10 10 10 40 생김 약 10분 걸림
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (heights[i] > 0)
			cout << heights[i] << "\n";
	}

	return 0;
}