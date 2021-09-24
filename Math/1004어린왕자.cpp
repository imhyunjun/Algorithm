#include <iostream>
#include <cmath>
using namespace std;

int SqrDis(int _x1, int _x2, int _y1, int _y2)
{
	return pow(_x1 - _x2, 2) + pow(_y1 - _y2, 2);
}

//true -> 점이 원 안에 있는 것, false이면 원 밖에
bool Check(int _cx, int _cy, int _cr, int _x, int _y)
{
	return SqrDis(_x, _cx, _y, _cy) <= _cr * _cr;
}

int main()
{
	int T;
	int x1, x2, y1, y2;
	int N;

	cin >> T ;

	for (int i = 0; i < T; i++)
	{
		int cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> N;

		for (int j = 0; j < N; j++)
		{
			int c1, c2, r;
			
			cin >> c1 >> c2 >> r;

			if (Check(c1, c2, r, x1, y1) != Check(c1, c2, r, x2, y2))
			{
				cnt++;
			}
		}

		cout << cnt << "\n";
	}


	return 0;
}