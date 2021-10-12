#include <stdio.h>
using namespace std;

int main()
{
	int N;
	int s;
	scanf_s("%d", &N);
	s = 2 * N - 1;

	for (int i = 1; i <= s;)
	{
		int tempi = 2 * N - i;
		for (int j = 0; j < (s - tempi) / 2; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < tempi; j++)
		{
			printf("*");
		}

		printf("\n");
		i += 2;
	}
	return 0;
}