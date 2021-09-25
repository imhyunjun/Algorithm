//블룸 필터
#include <iostream>
#include <vector>
using namespace std;

class Bloom_Filter
{
	vector<bool> data;
	int nBits;

	int Hash(int _num, int _key)
	{
		switch (_num)
		{
		case 0: return _key % nBits;
		case 1: return (_key / 7) % nBits;
		case 2:return (_key / 11) % nBits;
		}
		return 0;
	}

public:
	Bloom_Filter(int _n) : nBits(_n)
	{
		data = vector<bool>(nBits, false);
	}

	void LookUp(int _key)
	{
		bool result = data[Hash(0, _key)] & data[Hash(1, _key)] & data[Hash(2, _key)];

		if (result)
		{
			cout << _key << ": 있을 수 있음" << endl;
		}
		else
		{
			cout << _key << ": 절대 없음" << endl;
		}
	}
};

int main()
{
	return 0;
}