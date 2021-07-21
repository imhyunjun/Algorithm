#include <stdio.h>

int main()
{
	double A;
	double B;
	scanf_s("%lf", &A);
	scanf_s("%lf", &B);
	printf("%.9lf", A / B);

	return 0;
}