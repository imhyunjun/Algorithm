#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, M;
int notwork[10];
int start = 100;
int cnt = 0;

//최소는 아니지만 그나마 가까운 숫자 찾기
int FindNum()
{
	int sum = 0;
	int digits = 0;

	digits = to_string(N).length();

	if (N == 0) digits = 1;

	for (int i = digits; i > 0; i--)
	{
		int divisor = pow(10, i);
		int divisor2 = pow(10, i - 1);
		int r = (N % divisor) / divisor2;
		bool isNotWork = false;

		int exp = 0;
		int cnt = 1;
		int tempr = r;

		while (true)
		{
			isNotWork = false;


			if (notwork[tempr])
			{
				isNotWork = true;

				if (tempr == 0)
				{
					tempr = 1;
				}
				else
				{
					int d = pow(-1, exp);
					int p = r + d * cnt;
					if (p >= 0)
						tempr = p;

					if (d == -1)
						cnt++;
				}
			}
			else
			{
				isNotWork = false;
			}

			if (!isNotWork)
			{
				sum += tempr * divisor2;
				break;
			}

			exp++;
		}

	}

	return sum;
}

bool Check(int _n)
{
	int digits = to_string(_n).length();
	for (int i = digits; i > 0; i--)
	{
		int divisor = pow(10, i);
		int divisor2 = pow(10, i - 1);
		int r = (_n % divisor) / divisor2;

		if (notwork[r])
			return false;
	}

	return true;
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		notwork[x] = 1;
	}

	/*int num = FindNum();
	
	int start = 0;
	int end = 0;

	if (num >= N)
	{
		start = 2 * N - num;
		end = num;
	}
	else
	{
		start = num;
		end = 2 * N + num;
	}

	if (start < 0) start = 0;
	if (end == 0) end = 1000000;*/

	int minV = abs(100 - N);

	for (int i = 0; i <= 1000000; i++)
	{
		if (Check(i))
		{
			int cnt = abs(N - i) + to_string(i).length();
			minV = min(minV, cnt);
		}
	}

	cout << minV;

	return 0;
}