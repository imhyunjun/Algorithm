#include <iostream>
#include <list>

using namespace std;

int main()
{
	int T;
	int count = 0;
	list<char> password;
	list<char>::iterator curr_it;

	string input;

	cin >> T;

	while (count < T)
	{
		cin >> input;
		password.clear();
		curr_it = password.begin();

		for(int i = 0; i < input.length(); i++)
		{
			if (input[i] == '-')
			{
				if (curr_it != password.begin())
				{
					//이전 값 지우고 다시 iterator값
					password.erase((--curr_it)++);
				}			
			}
			else if (input[i] == '<')
			{
				if (curr_it != password.begin())
				{
					curr_it--;
				}
			}
			else if (input[i] == '>')
			{
				if (curr_it != password.end())
				{
					curr_it++;
				}
			}
			else
			{
				password.insert(curr_it, input[i]);
			}
		}

		for (curr_it = password.begin(); curr_it != password.end(); curr_it++)
		{
			cout << *curr_it;
		}

		cout << "\n";
		count++;
	}

	

	return 0;
}