#include <stdio.h>
#include <unordered_map>

using namespace std;

int N, M;

int main()
{
	unordered_map<int, int> cards;

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		cards[temp]++;
	}

	scanf_s("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		printf("%d ", cards[temp]);
	}

	return 0;
}