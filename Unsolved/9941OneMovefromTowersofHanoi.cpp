#include <stdio.h>
#include <cmath>

using namespace std;
using ulli = unsigned long long int;

ulli k;
long long int n;
ulli cnt = 0;
int caseNum = 0;
bool finished = false;

//k번째에 어떤 번호의 디스크가 어디서 어디로 움직이는지 구하는 것

void Hanoi1(int _disk, char _from, char _by, char _to)
{
	if (_disk <= 0) return;
	if (finished) return;

	Hanoi1(_disk - 1, _from, _to, _by);

	cnt++;

	if (cnt == k)
	{
		printf("Case %d: %d %c %c\n", caseNum, _disk, _from, _to);
		finished = true;
		return;
	}

	Hanoi1(_disk - 1, _by, _from, _to);
}

void Hanoi2(int _disk, char _from, char _by, char _to)
{
	if (_disk <= 0) return;
	if (finished) return;

	Hanoi2(_disk - 1, _from, _to, _by);

	cnt--;

	if (cnt == k )
	{
		printf("Case %d: %d %c %c\n", caseNum, _disk, _to, _from);
		return;
	}

	Hanoi2(_disk - 1, _by, _from, _to);
}

int main()
{
	while (true)
	{
		scanf_s("%llu %llu", &k, &n);
		caseNum++; 
		ulli std1 = (ulli)(pow(2, (n - 1)));

		n = 60;
		k = std1 / 2 - 1;

		if (k == 0 && n == 0) break;
		else
		{					
			finished = false;

			if (k < std1 / 2)
			{
				cnt = 0;
				Hanoi1(n - 1, 'A', 'C', 'B');
			}
			else if (std1 / 2 <= k && k < std1)
			{
				cnt = pow(2, n - 1);
				Hanoi2(n - 1, 'B', 'C', 'A');
			}
			else if (k == std1)		//가장 큰 원반이 c로 넘어가는 시점
			{
				printf("Case %d: %llu %c %c\n", caseNum, n, 'A', 'C');
			}
			else if (std1 < k && k < 3 * pow(2, n -2) - 1)
			{
				cnt = pow(2, n - 1);
				Hanoi1(n - 1, 'B', 'A', 'C');
			}
			else
			{
				cnt = pow(2, n);
				Hanoi2(n - 1, 'C', 'A', 'B');
			}
		}

	}

	return 0;
}

//n = 60에 대해 시간이 너무 많이 들음.. 나중에 알고리즘 수정 해보기 20210924