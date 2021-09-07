#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b;
vector<pair<int,int>> div1;
vector<pair<int,int>> div2;

void GetDivisor(int _num, vector<pair<int, int>>& _div)
{
	for (int i = 1; (i * i) <= _num; i++)
	{
		if (_num % i == 0)
		{
			_div.push_back(make_pair(i, _num / i));
		}
	}
}
int main()
{
	

	while (true)
	{
		int min = INT32_MAX;

		cin >> a >> b;
		if (a == 0 && b == 0) break;

		div1.clear();
		div2.clear();

		GetDivisor(a, div1);
		GetDivisor(b, div2);
		
		for (int i = 0; i < div1.size(); i++)
		{
			for (int j = 0; j < div2.size(); j++)
			{
				vector<int> temp = { div1[i].first, div1[i].second, div2[j].first, div2[j].second };
				sort(temp.begin(), temp.end());

				int sum = 0;
				for (int k = 0; k < temp.size() - 1; k++)
				{
					int p = temp[k];
					int q = temp[k + 1.0];

					sum += (p - q) * (p - q);
				}

				if (sum < min)
				{
					min = sum;
				}
			}
		}

		cout << min;
	}


	return 0;
}