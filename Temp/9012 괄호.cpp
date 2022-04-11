#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int j = 0; j < N; j++)
	{
		string s;
		cin >> s;

		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				sum++;
			}
			else
			{
				sum--;
			}

			if (sum < 0)
			{
				break;
			}
		}

		if (sum != 0) 
		{
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
	}

	return 0;
}