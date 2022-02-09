#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	vector<int> numbers;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		numbers.push_back(x);
	}

	sort(numbers.begin(), numbers.end());

	int integer;
	N--;

	integer = numbers[0] * numbers[N];

	cout << integer;


	return 0;
}