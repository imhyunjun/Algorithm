#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int cnt = 0;

int main()
{
	unordered_map<string, int> names;
	vector<string> name;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		names[temp]++;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (names[temp] == 1)
		{
			cnt++;
			name.push_back(temp);
			names[temp]++;
		}
	}

	cout << cnt << endl;
	sort(name.begin(), name.end());
	
	vector<string>::iterator iter;
	for (iter = name.begin(); iter != name.end(); iter++)
	{
		cout << *iter << endl;
	}
		
	return 0;
}