#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	vector<stack<int>> s;
	int N, P;
	cin >> N >> P;
	int cnt = 0;
	s.resize(6);
	for (int i = 0; i < 6; i++)
	{
		s[i].push(0);
	}

	for (int i = 0; i < N; i++)
	{
		int n, p;
		cin >> n >> p;
		n--;

		while (s[n].top() > p)
		{
			s[n].pop();
			cnt++;

		}

		if (s[n].top() != p)
		{
			s[n].push(p);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}