#include <iostream>
#include <set>
#include <queue>
#include <numeric>
#include <string>

std::string MakeCoprime(int a, int b)
{
	int gcd = std::gcd(a, b);
	a /= gcd;
	b /= gcd;
	std::string s = std::to_string(a) + "/" + std::to_string(b);
	return s;
}

int main()
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b;
		std::cin >> a >> b;		// a / b;
		int r = a % b;
		a = r;
		if (r == 0)
		{
			std::cout << 1 << "/" << 1 << "\n";
			continue;
		}

		int zero = 0;
		int one = 0;
		int q = 0;
		std::set<int> residues;
		std::queue<std::pair<int, int>> queue;

		while (true)
		{
			a *= 2;
			r = a % b;
			q = a / b;

			if (q == 0) zero++;
			if (q == 1) 
			{
				one++;
				a -= b;
			}

			if (r == 0)
			{
				std::cout << 1 << "/" << 1 << "\n";
				break;
			}

			if (residues.find(r) != residues.end())
			{
				while (!queue.empty())
				{
					if (queue.front().first == r)
					{
						break;
					}

					int tempq = queue.front().second;
					queue.pop();
					if (tempq == 0) 
					{
						zero--;
					}
					else if (tempq == 1)
					{
						one--;
					}
				}

				zero--;

				std::cout << MakeCoprime(one, one + zero) << "\n";
				break;
			}
			residues.insert(r);
			queue.push({r, q});
		}	
	}


	return 0;
}