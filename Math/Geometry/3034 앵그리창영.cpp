#include <iostream>

using namespace std;

int main()
{
	float N, W, H;

	cin >> N >> W >> H;

	for (int i = 0; i < N; i++)
	{
		float l;
		cin >> l;
		if (l * l > W * W + H * H)
		{
			cout << "NE" << "\n";
		}
		else
		{
			cout << "DA" << "\n";
		}
	}

	return 0;
}