#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	cout << "<";
	int idx = 1;
	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		if (idx == K)
		{
			if (f == K)
				cout << K;
			else
				cout << ", " << f;
			idx = 0;
		}
		else
		{
			q.push(f);
		}

		idx++;
	}

	cout << ">";



	return 0;
}