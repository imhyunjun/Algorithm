#include <iostream>
#include <string>
#include <list>

using namespace std;


int main()
{
	//ios_base::sync_with_stdio(false);
	//cout.tie(NULL);
	//cin.tie(NULL);

	string init;
	int count;
	char a;

	cin >> init;
	cin >> count;

	list<char> c(init.begin(), init.end());

	auto it = c.end();

	while (count--)
	{
		cin >> a;

		if (a == 'L')
		{
			if (it != c.begin())
			{
				it--;
			}
		}
		else if (a == 'D')
		{
			if (it != c.end())
			{
				it++;
			}
		}
		else if (a == 'B')
		{
			if (it != c.begin())
			{
				it--;
				c.erase(it++);
			}
		}
		else if (a == 'P')
		{
			char x;
			cin >> x;

			c.insert(it, x);
		}
	}

	for (auto& x : c)
	{
		cout << x;
	}

	return 0;
}