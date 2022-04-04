#include <iostream>
#include <set>

using namespace std;

int N;
int cnt;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		set<char> sc;
		bool isGroup = true;
		cin >> s;

		sc.insert(s[0]);

		for (int j = 1; j < s.size(); j++)
		{
			char currentC = s[j];
			char prevC = s[j - 1];

			if (prevC != currentC)
			{
				////c++ 20
				//if (sc.contains(currentC))
				//{
				//	isGroup = false;
				//	break;
				//}
				//else
				//{
				//	sc.insert(currentC);
				//}

				if (sc.find(currentC) != sc.end())
				{
					isGroup = false;
					break;
				}
				else
				{
					sc.insert(currentC);
				}
			}
		}

		if (!isGroup)
			cnt++;

	}

	cout << N - cnt;

	return 0;
}