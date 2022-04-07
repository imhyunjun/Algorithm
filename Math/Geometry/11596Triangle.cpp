#include <iostream>

using namespace std;

int a1, b1, c1, a2, b2, c2;

void Sort(int& _a, int& _b, int& _c)
{
	int a, b, c; //c를 가장 긴 변으로 정할 것

	if (_a > _b)
	{
		if (_a > _c)
		{
			c = _a;
			a = _b;
			b = _c;
		}
		else
		{
			c = _c;
			a = _a;
			b = _b;
		}
	}
	else   //_b >= a
	{
		if (_b > _c)
		{
			c = _b;
			a = _a;
			b = _c;
		}
		else
		{
			c = _c;
			b = _b;
			a = _a;
		}

	}

	_c = c;
	_b = b;
	_a = a;

	//2, 3번째 정렬

	if (_a > _b)
	{
		int temp = _a;
		_a = _b;
		_b = temp;
	}
}

bool Pythagoras(int _a, int _b, int _c)
{
	return _c * _c == _a * _a + _b * _b;
}

int main()
{
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;

	Sort(a1, b1, c1);
	Sort(a2, b2, c2);

	cout << a1 << b1 << c1 << endl << a2 << b2 << c2;

	if (Pythagoras(a1, b1, c1) && Pythagoras(a2, b2, c2))
	{
		if (a1 == a2 && b1 == b2 && c1 == c2)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	else
	{
		cout << "NO";
	}

	return 0;
}