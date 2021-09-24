#include <iostream>

using namespace std;

int Dis(int _x1, int _x2, int _y1, int _y2)
{
	return (_x1 - _x2) * (_x1 - _x2) + (_y1 - _y2) * (_y1 - _y2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int sqrDis = Dis(x1, x2, y1, y2);
		int rs = (r1 + r2) * (r1 + r2);
		int rm = (r1 - r2) * (r1 - r2);

		if (rs < sqrDis)
			cout << 0 << "\n";
		else if (rs == sqrDis)
			cout << 1 << "\n";
		else
		{
			if (r1 == r2)
			{
				if(sqrDis == 0) cout << -1 << "\n";
				else cout << 2 << "\n";
			}
			else
			{
				if(rm == sqrDis) cout << 1 << "\n";
				else if(rm > sqrDis) cout << 0 << "\n";
				else cout << 2 << "\n";
			}
		}
	}

	return 0;
}