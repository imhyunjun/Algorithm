#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string number[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

bool Comp(pair<string, int> _a, pair<string, int> _b)
{
	return _a.first < _b.first;
}

int main()
{
	int M, N;
	cin >> M >> N;

	vector<pair<string, int>> num;
	for (int i = M; i <= N; i++)
	{
		string s = to_string(i);
		string newS = "";
		for (int j = 0; j < s.length(); j++)
		{
			int temp = s[j] - '0';
			newS += number[temp];
		}
		
		num.push_back({ newS, i });
	}

	sort(num.begin(), num.end(), Comp);

	for (int i = 0; i < N - M + 1; i++)
	{
		cout << num[i].second << " ";
		if (i % 10 == 9) cout << "\n";
	}

	return 0;
}