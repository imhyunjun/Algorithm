#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Median
{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	void Insert(int _data)
	{
		if (maxHeap.size() == 0)
		{
			maxHeap.push(_data);
			return;
		}

		if (maxHeap.size() == minHeap.size())
		{
			if (_data <= Get())
				maxHeap.push(_data);
			else
				minHeap.push(_data);

			return;
		}

		if (maxHeap.size() < minHeap.size())
		{
			if (_data > Get())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(_data);
			}
			else
				maxHeap.push(_data);

			return;
		}

		if (_data < Get())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(_data);
		}
		else
			minHeap.push(_data);
	}

	float Get()
	{
		if (maxHeap.size() == minHeap.size())
		{
			return (maxHeap.top() + minHeap.top()) / 2.0f;
		}
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		return maxHeap.top();
	}
};

int main()
{
	Median med;

	med.Insert(1);
	med.Insert(5);
	med.Insert(2);
	med.Insert(10);
	med.Insert(40);

	cout << med.Get();

	return 0;
}