#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int l = s.length();
	int currentPipe = 0;
	int sum = 0;

	for (int i = 0; i < l; i++)
	{
		if (i < l - 1 && s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				sum += currentPipe;
			}
			else
			{
				currentPipe++;
				sum++;
			}
		}
		else if(i > 0 && s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				
			}
			else
			{
				currentPipe--;
			}
		}
	}

	cout << sum;

	return 0;
}