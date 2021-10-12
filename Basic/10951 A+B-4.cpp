#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int A, B;
		cin >> A >> B;
		if (cin.eof()) break;

		cout << A + B << "\n";
	}

	return 0;
}