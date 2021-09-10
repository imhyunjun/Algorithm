#include <stdio.h>

using namespace std;

int N;		//�� ���� ���� - 7
int L;		//1���� ���� - 2
int C;		//cd ����� ������ ���� �뷡�� �뷡 ���̿��� 1�� - 6

/*CD����� ���� ���� = A
C>= L + (A-1) * (L+1)
A -1 <= C - L / L +1
A <= C +1 / L + 1
A > 0*/


int main()
{
	scanf_s("%d %d %d", &N, &L, &C);

	int s = (C + 1) / (L + 1);		//A�� ���� -> �� ���ϱ�
	int A = 1;

	for (int i = 1; i < s + 1; i++)
	{
		int tempL = L + (i - 1) * (L + 1);		//cd����� ���� ������ i�϶� ���� ����

		if (C - tempL < L + 1)			//�� ä��
		{
			if (i % 13 == 0)		//�� ä���µ� 13�� ����� �ϳ� ���̱�
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
