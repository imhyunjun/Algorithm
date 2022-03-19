#include <iostream>
#include <vector>

using namespace std;

unsigned long long n;
vector<long long> sum;

long long Fibonacci(long long _n)
{
	if (_n == 0) return sum[0];
	else if (_n == 1) return sum[1];
	else if (_n >= 2)
	{
		if (sum.size() <= _n)
		{
			long long f = Fibonacci(_n - 1) + Fibonacci(_n - 2);
			sum.push_back(f % 1000000);
			return f % 1000000;
		}
		else
		{
			return sum[_n];
		}
	}	
}

int main()
{
	cin >> n;

	sum.push_back(0);
	sum.push_back(1);

	long long answer = Fibonacci(n);
	cout << answer;
}

//메모리 초과