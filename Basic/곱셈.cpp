#include <stdio.h>

int main()
{
	int A, B;
	scanf_s("%d\n %d", &A, &B);

	printf("%d\n", A * (B % 10));
	printf("%d\n", A * (B % 100 - B % 10) / 10);
	printf("%d\n", A * (B / 100));
	printf("%d\n", A * B);

	return 0;
}