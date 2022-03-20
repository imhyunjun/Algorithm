#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int cnt = 0;

bool CheckSequence(int _n)
{
	vector<int> num;

	for (int i = 1; i < 5; i++)
	{
		int divisor1 = pow(10, i);
		int divisor2 = pow(10, i - 1);
		if (_n < divisor2) break;
		int residue = (_n % divisor1) / divisor2;

		num.push_back(residue);
	}

	if (num.size() > 2)
	{
		for (int i = 0; i < num.size() - 2; i++)
		{
			int a1 = i + 1;
			int a2 = i + 2;
			int difference1 = num[i] - num[a1];
			int difference2 = num[a1] - num[a2];

			if (difference1 != difference2) return false;
		}
	}

	cnt++;
	return true;
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		CheckSequence(i);
	}

	cout << cnt;

	return 0;
}