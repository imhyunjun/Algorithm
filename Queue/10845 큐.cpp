#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

ostream& operator<<(ostream& _os, queue<int>& _q)
{
	if (!_q.empty()) _os << _q.front() << "\n";
	else _os << -1 << "\n";

	return _os;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int b;
			cin >> b;
			q.push(b);
		}
		else if (s == "pop")
		{
			cout << q;
			if(!q.empty()) q.pop();
		}
		else if (s == "size")
		{
			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front")
		{
			cout << q;
		}
		else if (s == "back")
		{
			if (!q.empty()) cout << q.back() << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}