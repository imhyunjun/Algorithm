#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

list<vector<int>> pos;
vector<vector<int>> sorting;
list<vector<int>>::iterator it;
list<vector<int>>::iterator curr_it;

void Check(int _dir, int _sign)
{
	for (it = pos.begin(); it != pos.end(); it++)
	{
		int xOffset = (*it)[0] - (*curr_it)[0];
		int yOffset = (*it)[1] - (*curr_it)[1];

		if (xOffset == 0) continue;

		if (yOffset / xOffset == _dir && xOffset * _sign > 0)
		{
			pos.erase(curr_it);
			curr_it = it;
			return;
		}
	}
}

bool Comp(vector<int> _a, vector<int> _b)
{
	vector<int> first = pos.front();
	return (pow((first[0] - _a[0]), 2.0) + pow((first[1] - _a[1]), 2) < pow((first[0] - _b[0]), 2) + pow((first[1] - _b[1]), 2));
}

int main()
{
	int N, K;	//식물의 수, 점프 수
	int x, y;
	string dir;

	cin >> N >> K >> dir;

	cin >> x >> y;
	vector<int> temp = { x, y };
	pos.push_back(temp);
	
	for (int i = 1; i < N; i++)
	{
		cin >> x >> y;

		int r = (pos.front()[0] + pos.front()[1]) % 2;

		if (r == (x + y) % 2)
		{
			vector<int> temp = { x, y };
			sorting.push_back(temp);
		}
	}

	sort(sorting.begin(), sorting.end(), Comp);

	for (vector<int> data : sorting)
	{
		pos.push_back(data);
	}

	curr_it = pos.begin();

	for (int i = 0; i < K; i++)
	{
		switch (dir[i])
		{
		case 'A':	//1사분면
			Check(1, 1);
			break;
		case 'B':	//4사분면
			Check(-1, 1);
			break;
		case 'C':	//2사분면
			Check(-1, -1);
			break;
		case 'D':	//3사분면
			Check(1, -1);
			break;
		default:
			break;
		}
	}

	cout << (*curr_it)[0] <<" "<< (*curr_it)[1];
}

//시간초과 ㅜㅜㅜ