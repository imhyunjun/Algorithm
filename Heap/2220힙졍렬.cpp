#include <stdio.h>

using namespace std;

int heap[1000000];
int n;

void swap(int a, int b)
{
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

int main()
{
	scanf_s("%d", &n);
	heap[0] = 1;		//1을 먼저 넣는다

	//2부터 차례로 넣기
	for (int i = 1; i < n; i++)
	{
		heap[i] = i + 1;

		swap(i, i-1);

		for (int j = i - 1; j > 0;)
		{
			if (j % 2 == 0)
			{
				swap(j, (j - 2) / 2);
				j = (j - 2) / 2;
			}
			else
			{
				swap(j, (j - 1) / 2);
				j = (j - 1) / 2;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", heap[i]);
	}

	return 0;
}