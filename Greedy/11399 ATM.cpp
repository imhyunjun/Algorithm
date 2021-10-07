#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int N;
	vector<int> time;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		time.push_back(t);
	}

	sort(time.begin(), time.end());

	for (int i = 1; i < N; i++)
	{
		time[i] += time[i - 1];
	}

	int sum = accumulate(time.begin(), time.end(), 0);

	cout << sum;

	return 0;
}