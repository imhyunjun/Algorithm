//체이닝을 이용한 해시 테이블

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using uint = unsigned int;
using namespace std;

class Hash_Map
{
	vector<list<int>> data;

public:
	Hash_Map(size_t _n)
	{
		data.resize(_n);
	}

	void Insert(uint _v)
	{
		int n = data.size();
		data[_v % n].push_back(_v);
	}

	bool Find(uint _v)
	{
		int n = data.size();
		auto& entries = data[_v % n];
		return find(entries.begin(), entries.end(), _v) != entries.end();
	}
	//이전 함수보다는 느림
};