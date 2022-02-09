#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Mito
{
public:
	Mito(Mito* _f, Mito* _m, char _s, int _idx)
	{
		father = _f;
		mother = _m;
		sex = _s;
		idx = _idx;
	}
	
	Mito* father;
	Mito* mother;
	int idx;
	char sex;
};

int FindMother(Mito* _mito)
{
	if (_mito->mother == 0) return _mito->idx;

	if (_mito->mother != 0) FindMother(_mito->mother);
}

int n, m;		//n -> 초기 개체, m : 출생과 죽음의 합
vector<int> alive;
vector<Mito*> mitos;
vector<int> mother;

int main()
{
	cin >> n;
	int k = n + 1;
	mitos.resize(k);
	alive.resize(k);

	for (int i = 0; i < n; i++)
	{
		char sex;
		cin >> sex;

		int t = i + 1;
		mitos[t] = new Mito(0, 0, sex, i + 1);
		alive[t] = 1;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;

		if (x > 0)
		{
			int y;
			char z;
			cin >> y >> z;

			mitos.push_back(new Mito(mitos[x], mitos[y], z, (int)mitos.size()));
			alive.push_back(1);
		}
		else
		{
			alive[-x] = -1;
		}
	}

	map<int, int> ma;
	map<int, int> cnt;
	map<int, int> code;

	for (int i = 0; i < alive.size(); i++)
	{
		if (alive[i] == 1)
		{
			ma.insert({ i, FindMother(mitos[i])});
		}
	}

	int kk;
	cin >> kk;

	for (int i = 0; i < kk; i++)
	{
		int x, y;
		cin >> x >> y;
		code[x] = y;
	}

	int temp = (*ma.begin()).second;
	map<int, int>::iterator it = ma.begin();
	it++;
	int num = 0;

	for (it; it != ma.end(); it++)
	{
		if (temp != (*it).second)
		{
			if (code.contains((*it).first) && code.contains((*ma.begin()).first))
			{
				if (code[(*it).first] != code[(*ma.begin()).first])
				{
					cout << "NO";
					return 0;
				}
			}
		}
		else
		{
			num++;
		}
	}

	if (num == ma.size()) cout << "YES";
	else
		cout << "POSSIBLY";

	return 0;
}

//구조를 다시 생각