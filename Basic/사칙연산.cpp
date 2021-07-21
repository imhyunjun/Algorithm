#include <stdio.h>

int main()
{
	int A, B;
	scanf_s("%d %d", &A, &B);
	printf("%d\n", A + B);
	printf("%d\n", A - B);
	printf("%d\n", A * B);

	if (B != 0)
	{
		printf("%d\n", A / B);
		printf("%d\n", A % B);
	}

	return 0;
}