#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <stdio.h>

using namespace std;

int N, M;
string names2[100001];
char str[21];

int main()
{
	map<string, int> names;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		names.insert(make_pair(str, i));
		names2[i] = str;
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%s", str);

		if (isdigit(str[0]))
		{
			int a = stoi(str);
			cout << names2[a - 1] << "\n";
		}
		else
		{
			printf("%d\n", names[str] + 1);
		}
	}
	return 0;
}