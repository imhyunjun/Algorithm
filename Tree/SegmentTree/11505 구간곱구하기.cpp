#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000000007

vector<int> segTree;
vector<int> input;

long long Init(int _idx, int _s, int _e)
{
	if (_s == _e)
	{
		return segTree[_idx] = input[_s] % MAX;
	}

	int mid = (_s + _e) / 2;
	long long left = Init(2 * _idx + 1, _s, mid);
	long long right = Init(2 * _idx + 2, mid + 1, _e);

	return segTree[_idx] = (left * right) % MAX;
}

long long Mul(int _n, int _f, int _l, int _s, int _e)
{
	if (_s > _l || _e < _f) return 1;
	if (_s <= _f && _l <= _e) return segTree[_n];

	int mid = (_f + _l) / 2;
	long long left = Mul(2 * _n + 1, _f, mid, _s, _e);
	long long right = Mul(2 * _n + 2, mid + 1, _l, _s, _e);

	return (left * right) % MAX;
}

long long ChangeNum(int _n, int _s, int _e, int _idx, long long _num)	
{
	if (_idx < _s || _idx > _e) return segTree[_n];
	if (_s == _e)
	{
		return segTree[_n] = _num;
	}

	int mid = (_s + _e) / 2;

	long long l = ChangeNum(2 * _n + 1, _s, mid, _idx, _num);
	long long r = ChangeNum(2 * _n + 2, mid + 1, _e, _idx, _num);

	return segTree[_n] = (l * r) % MAX;	
}



int main()
{
	int N, M, K;

	cin >> N >> M >> K;

	input.resize(N);
	int t_size = (1 << (int)(ceil(log2(N) + 1))) - 1;
	segTree.resize(t_size);


	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	Init(0, 0, N - 1);


	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			ChangeNum(0, 0, N - 1, b-1, c);
		}
		else if (a == 2)
		{
			cout << Mul(0, 0, N - 1, b - 1, c - 1) % MAX << "\n";
		}
	}
	return 0;
}