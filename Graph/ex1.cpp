//노드가 N개 ->  N*N배열로 표현 가능
//인접 행렬 : data[1][2]는 1과 2 사이의 가중치( 무방향 그래프 )

#include <iostream>
#include <vector>

using namespace std;

enum class city : int
{
	MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

struct Graph
{
	vector<vector<int>> data; // -> 노드의 개수가 V 면 총 메모리는 V*V를 사용 -> 이를 줄일수 있는 방법 생각
	                          // 행렬 : 연결되어 있지 않은 노드들도 데이터를 저장해야 한다. -> 이 대신 직접 연결되어 있는 노드의 ID만 저장
								// -> 인접 리스트 사용

	Graph(int _n)
	{
		data.reserve(_n);		//capacity 조절
		vector<int> row(_n);
		fill(row.begin(), row.end(), -1);

		for (int i = 0; i < _n; i++)
		{
			data.push_back(row);
		}
	}

	void AddEdge(const city _c1, const city _c2, int _dis)
	{
		auto n1 = static_cast<int>(_c1);
		auto n2 = static_cast<int>(_c2);
		data[n1][n2] = _dis;
		data[n2][n1] = _dis;
	}

	void RemoveEdge(const city _c1, const city _c2)
	{
		auto n1 = static_cast<int>(_c1);
		auto n2 = static_cast<int>(_c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1;
	}
};

int main()
{
	Graph g(6);
	g.AddEdge(city::DUBAI, city::SEATTLE, 3000);

	return 0;
}