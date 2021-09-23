#include <iostream>
#include <vector>

using uint = unsigned int;
using namespace std;

class Hash_Map
{
	vector<int> data;

public:
	Hash_Map(size_t _n)
	{
		data = vector<int>(_n, -1);
	}

	void Insert(uint _v)
	{
		int n = data.size();
		data[_v % n] = _v;
	}
	//중복되 값이 들어올 경우 나중의 값으로 대체됨 -> 충돌 발생

	bool Find(uint _v)
	{
		int n = data.size();
		return (data[_v % n] == _v);
	}

	void Erase(uint _v)
	{
		int n = data.size();
		if (data[_v % n] == _v)
		{
			data[_v % n] = -1;
		}
	}
};