//인접 리스트

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class city : int
{
	MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

struct Graph
{
	vector<vector<pair<int, int>>> data; 
							  
							
	Graph(int _n)
	{
		data = vector<vector<pair<int, int>>>(_n, vector<pair<int, int>>());		//초기상태는 비어 있음
	}

	void AddEdge(const city _c1, const city _c2, int _dis)
	{
		auto n1 = static_cast<int>(_c1);
		auto n2 = static_cast<int>(_c2);
		data[n1].push_back({ n2, _dis });
		data[n2].push_back({ n1, _dis });
	}

	void RemoveEdge(const city _c1, const city _c2)
	{
		auto n1 = static_cast<int>(_c1);
		auto n2 = static_cast<int>(_c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair)
		{
			return pair.first == n2;
		});

		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair)
		{
			return pair.first == n1;
		});
	}
};

int main()
{
	Graph g(6);
	g.AddEdge(city::DUBAI, city::SEATTLE, 3000);

	return 0;
}