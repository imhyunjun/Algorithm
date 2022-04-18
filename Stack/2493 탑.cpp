#include <iostream>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::stack<std::pair<int, int>> tower;
	std::cin >> N;

	int max = 0;

	for (int i = 0; i < N; i++)
	{
		int t;
		std::cin >> t;

		while (true)
		{
			if (t > max)
			{
				tower = std::stack<std::pair<int, int>>();
				max = t;
				tower.push({ t, i });
				std::cout << 0 << " ";
				break;
			}
			else if(tower.top().first >=  t)
			{
				std::cout << tower.top().second + 1 << " ";
				tower.push({ t, i });
				break;
			}
			else if (tower.top().first < t)
			{
				tower.pop();
			}				
		}
	}

	return 0;
}