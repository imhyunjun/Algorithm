#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		string p;
		int n;
		string a;
		bool isError = false;

		cin >> p >> n >> a;
		string as;
		vector<string> asv;
		if (a.size() > 2)
			as = a.substr(1, a.size() - 2);
		else
			as = "";
		asv = split(as, ',' );

		for (int i = 0; i < p.size(); i++)
		{
			char f = p.at(i);
			if (f == 'R')
			{
				int half = n / 2;
				if (half > 1)
				{
					for (int i = 0; i < half; i++)
					{
						string temp = asv[i];
						asv[i] = asv[n - i - 1];
						asv[n - i - 1] = temp;
					}
				}
			}
			else if (f == 'D')
			{
				if (asv.size() < 1 || asv[0] == "0")
				{
					isError = true;
					cout << "error" << "\n";
				}
				else
				{
					if(asv.size() >= 1)
						asv[asv.size() - 1] = "0";

					for (int i = 0; i < n - 1; i++)
					{
						asv[i] = asv[i + 1];
						asv[i + 1] = "0";
					}
				}
			}
		}

		if (!isError)
		{
			cout << "[" << asv[0];
			for (int i = 1; i < n; i++)
			{
				if (asv[i] == "0")
				{
					cout << "]" << "\n";
					break;
				}
				else
				{
					cout << "," << asv[i];
				}
			}
		}

		T--;
	}

	return 0;
}