//뻐꾸기 해싱
#include <iostream>
#include <vector>

using namespace std;

class Hash_Map
{
	vector<int> data1;
	vector<int> data2;
	int size;

	int Hash1(int _key) const
	{
		return _key % size;
	}

	int Hash2(int _key) const
	{
		return (_key / size) % size;
	}

public:
	Hash_Map(int _n) : size(_n)
	{
		data1 = vector<int>(size, -1);
		data2 = vector<int>(size, -1);
	}

	vector<int>::iterator LookUp(int _key)
	{
		auto hash_value1 = Hash1(_key);
		if (data1[hash_value1] == _key)
		{
			return data1.begin() + hash_value1;
		}

		auto hash_value2 = Hash2(_key);
		if (data2[hash_value2] == _key)
		{
			return data2.begin() + hash_value2;
		}

		return data2.end();
	}

	void Erase(int _key)
	{
		auto position = LookUp(_key);
		if (position != data2.end())
		{
			*position = -1;
		}
		else
		{
			cout << "키가 없습니다" << endl;
		}
	}

	void Insert(int _key)
	{

	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="_key"></param>
	/// <param name="_cnt"></param> 호출 횟수
	/// <param name="_table"></param> 키를 삽입할 테이블 번호
	void InsertImpl(int _key, int _cnt, int _table)
	{
		if (_cnt > size)
		{
			//삽입시 순환 발생
			return;
		}

		if (_table == 1)
		{
			int hash = Hash1(_key);
			if (data1[hash] == -1)
			{
				data1[hash] = _key;
			}
			else
			{
				int old = data1[hash];
				data1[hash] = _key;
				InsertImpl(old, _cnt + 1, 2);
			}
		}
		else
		{
			int hash = Hash2(_key);
			if (data2[hash] == -1)
			{
				data2[hash] = _key;
			}
			else
			{
				int old = data2[hash];
				data2[hash] = _key;
				InsertImpl(old, _cnt + 1, 1);
			}
		}
	}
};