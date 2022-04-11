#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int V, E;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> V >> E;
		cout << 2 - V + E << "\n";
	}

	return 0;
}