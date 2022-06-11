#include <iostream>
#include <map>

using namespace std;

int N;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		map<string, int> clothes;
		for (int j = 0; j < N; j++)
		{
			string a, b;
			cin >> a >> b;
			clothes[b]++;
		}

		int cnt = 1;

		for (map<string, int>::iterator it = clothes.begin(); it != clothes.end(); it++)
		{
			cnt *= (it->second + 1);
		}
		cnt--;

		cout << cnt << "\n";
	}

	return 0;
}