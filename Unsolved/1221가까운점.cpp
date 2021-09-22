#include <stdio.h>
#include <vector>
using namespace std;

vector<int> pos[150000];
int N;
int minD;
int cnt;

int GetDistanceSqr(vector<int> _p1, vector<int> _p2)
{
	return (_p1[0] - _p2[0]) * (_p1[0] - _p2[0]) + (_p1[1] - _p2[1]) * (_p1[1] - _p2[1]) + (_p1[2] - _p2[2]) * (_p1[2] - _p2[2]);
}

int main()
{
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int t;
			scanf_s("%d", &t);
			pos[i].push_back(t);
		}
	}

	cnt = 1;
	minD = GetDistanceSqr(pos[0], pos[1]);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (GetDistanceSqr(pos[i], pos[j]) < minD)
			{
				minD = GetDistanceSqr(pos[i], pos[j]);
				cnt = 1;
			}
			else if (GetDistanceSqr(pos[i], pos[j]) == minD)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", minD);
	printf("%d\n", cnt);

	return 0;
}

//시간 초과 나중에 다른 방법을 찾아봐야 20210922