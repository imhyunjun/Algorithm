#include <stdio.h>

using namespace std;

int N;		//총 곡의 개수 - 7
int L;		//1곡의 길이 - 2
int C;		//cd 한장당 가능한 길이 노래와 노래 사이에는 1초 - 6

/*CD한장당 곡의 개수 = A
C>= L + (A-1) * (L+1)
A -1 <= C - L / L +1
A <= C +1 / L + 1
A > 0*/


int main()
{
	scanf_s("%d %d %d", &N, &L, &C);

	int s = (C + 1) / (L + 1);		//A는 정수 -> 몫만 구하기
	int A = 1;

	for (int i = 1; i < s + 1; i++)
	{
		int tempL = L + (i - 1) * (L + 1);		//cd한장당 곡의 개수가 i일때 실제 길이

		if (C - tempL < L + 1)			//꽉 채움
		{
			if (i % 13 == 0)		//꽉 채웠는데 13의 배수면 하나 줄이기
			{
				A = i - 1;
			}
			else
			{
				A = i;
			}
		}
	}

	int r = N % A;

	if (r == 0)
		printf("%d", N / A);
	else
	{
		if (r % 13 == 0 && r == A -1)
		{
			printf("%d", N / A + 2);
		}
		else
			printf("%d", N / A + 1);

	}

	return 0;
}
