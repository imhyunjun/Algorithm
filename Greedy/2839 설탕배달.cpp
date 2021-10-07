#include <iostream>

using namespace std;

int N;

int Greedy()
{
	int quotient_5 = N / 5;

	while (true)
	{
		int remain_5 = N - quotient_5 * 5;

		if (remain_5 % 3 == 0)
		{
			return (remain_5 / 3) + quotient_5;
		}
		else
		{
			if (quotient_5 == 0) break;
			else quotient_5--;
		}
	}

	return -1;
}


int main()
{

	cin >> N;

	cout << Greedy();


	return 0;
}