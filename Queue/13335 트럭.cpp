#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, w, L;
	queue<int> bridge;
	queue<int> trucks;
	int currentWeight = 0;
	int time = 0;

	cin >> n >> w >> L;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		trucks.push(t);
	}

	while (true)
	{
		if (bridge.size() == w)
		{
			currentWeight -= bridge.front();
			bridge.pop();
		}

		int t = trucks.front();
		if (currentWeight + t <= L)
		{
			trucks.pop();
			bridge.push(t);
			currentWeight += t;
		}
		else
		{
			bridge.push(0);
		}

		time++;

		if (trucks.empty())
		{
			time += w;
			break;
		}
	}

	cout << time;

	return 0;
}