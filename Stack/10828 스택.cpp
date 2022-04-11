#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> st;

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
		string a = s.substr(0, 2);
		if (a == "pu")
		{
			int b;
			cin >> b;
			st.push(b);
		}
		else if (a == "po")
		{
			if (st.empty()) cout << -1 << "\n";
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (a == "si")
		{
			cout << st.size() << "\n";
		}
		else if (a == "em")
		{
			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (a == "to")
		{
			if (st.empty()) cout << -1 << "\n";
			else cout << st.top() << "\n";
		}
	}
	return 0;
}