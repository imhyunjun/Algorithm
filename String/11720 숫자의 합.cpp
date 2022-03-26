#include <iostream>

using namespace std;

int main()
{
	string s;
	int cnt;

	cin >> cnt;
	cin >> s;

	int sum = 0;

	for (int i = 0; i < cnt; i++)
	{
		char ss = s[i];
		int nn = (int)ss - 48;
		sum += nn;
	}

	cout << sum;
}