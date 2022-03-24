#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> nums;

	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int min = *nums.begin();
	int max = *(nums.end() - 1);
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;

		int start = 0;
		int end = N - 1;

		while (true)
		{
			if (n < min || n > max)
			{
				cout << 0 << " ";
				break;
			}
			else
			{
				int mid = (start + end) / 2;

				if (nums[mid] > n)
				{
					end = mid - 1;
				}
				else if (nums[mid] < n)
				{
					start = mid + 1;
				}
				else
				{
					cout << 1 << " ";
					break;
				}
			}

			if (start > end)
			{
				cout << 0 << " ";
				break;
			}
		}
	}

	return 0;
}