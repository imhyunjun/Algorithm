#include <iostream>

using namespace std;

int durability_less_zero = 0;

class Belt
{
public:
	Belt() : idx(0), durability(0) {}
	Belt(int _idx, int _d) : idx(_idx), durability(_d) {}
	void SetRobot()
	{
		if (durability <= 0) return;

		durability--;
		if (durability <= 0 && !checked)
		{
			durability_less_zero++;
			checked = true;
		}
		hasRobot = true;
	}

	void DeleteRobot()
	{
		hasRobot = false;
	}

public:
	int idx;
	int durability;
	bool hasRobot = false;
	bool checked = false;
};

int N, K;
Belt belts[200];

void RotateBelt()
{
	Belt last = belts[2 * N - 1];
	for (int i = 2 * N - 1; i > 0; i--)
	{
		belts[i] = belts[i - 1];
		if (i == N - 1)
		{
			if (belts[i].hasRobot)
			{
				belts[i].DeleteRobot();
			}
		}
	}
	belts[0] = last;
}

void RotateRobot()
{
	for (int i = N - 2; i >= 0; i--)
	{
		int cur = i;
		int next = cur + 1;
		if (belts[cur].hasRobot && !belts[next].hasRobot && belts[next].durability > 0)
		{
			belts[cur].DeleteRobot();
			belts[next].SetRobot();

			if (next == N - 1)
			{
				belts[next].DeleteRobot();
			}
		}
	}


}

int main()
{
	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++)
	{
		int d;
		cin >> d;
		Belt b(i, d);
		belts[i] = b;
	}

	int processCnt = 0;
	int tt = 0;
	while (durability_less_zero < K)
	{
		processCnt++;	
		RotateBelt();
		RotateRobot();
		belts[0].SetRobot();
	}

	cout << processCnt;

	return 0;
}