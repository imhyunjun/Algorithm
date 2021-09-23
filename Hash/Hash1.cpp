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
	//�ߺ��� ���� ���� ��� ������ ������ ��ü�� -> �浹 �߻�

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