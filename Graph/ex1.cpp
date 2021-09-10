//��尡 N�� ->  N*N�迭�� ǥ�� ����
//���� ��� : data[1][2]�� 1�� 2 ������ ����ġ( ������ �׷��� )

#include <iostream>
#include <vector>

using namespace std;

enum class city : int
{
	MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

struct Graph
{
	vector<vector<int>> data; // -> ����� ������ V �� �� �޸𸮴� V*V�� ��� -> �̸� ���ϼ� �ִ� ��� ����
	                          // ��� : ����Ǿ� ���� ���� ���鵵 �����͸� �����ؾ� �Ѵ�. -> �� ��� ���� ����Ǿ� �ִ� ����� ID�� ����
								// -> ���� ����Ʈ ���

	Graph(int _n)
	{
		data.reserve(_n);		//capacity ����
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