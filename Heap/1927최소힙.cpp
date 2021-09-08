#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> minHeap;

void Calculate(int _data)
{
	if (_data == 0)
	{
		if (minHeap.empty())
		{
			printf("%d", 0);
		}
		else
		{
			printf("%d", minHeap.top());
			minHeap.pop();
		}
	}
	else
	{
		minHeap.push(_data);
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		Calculate(x);
	}

	return 0;
}