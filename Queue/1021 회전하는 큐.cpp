#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int cnt = 0;

void Move(int _idx, int _goal, deque<int>& _deque)
{
	if (_deque.front() == _goal)
	{
		_deque.pop_front();	
		return;
	}
	//목표가 1번에 더 가깝다면
	else if ((_idx - 1.0) < (1 + _deque.size() - _idx))
	{
		int x = _deque.front();
		_deque.pop_front();
		_deque.push_back(x);
		cnt++;

		Move(_idx, _goal, _deque);
	}
	//목표가 뒤쪽으로 더 가깝다면
	else
	{
		int x = _deque.back();
		_deque.pop_back();
		_deque.push_front(x);
		cnt++;
		Move(_idx, _goal, _deque);
	}
}

int main()
{
	int N, M;

	deque<int> circle;
	vector<int> goal;

	cin >> N >> M;

	//1 - N 까지 
	for (int i = 1; i < N + 1; i++)
	{
		circle.push_back(i);
	}

	goal.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> goal[i];
	}

	for (int i = 0; i < M; i++)
	{
		int idx = 1;
		for (int j = 0; j < circle.size(); j++)
		{
			if (circle[j] == goal[i])
			{
				idx = j + 1;
				break;
			}
		}
		Move(idx, goal[i], circle);
	}

	cout << cnt;

	return 0;
}