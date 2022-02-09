//�׷��� �÷��� - ������ ���� �ٸ���

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

//�׷��� �ڷᱸ�� - ������Ʈ ��� ���, �켱 ���� ����ü
template <typename T>
struct Edge
{
public:
	unsigned src;
	unsigned dst;
	T weight;

	//���� �񱳴� ����ġ�� �̿�
	inline bool operator<(const Edge<T>& e)const
	{
		return this->weight < e.weight;
	}

	inline bool operator>(const Edge<T>& e)const
	{
		return this->weight > e.weight;
	}
};

template <typename T>
class Graph
{
public:
	//N���� �������� ������ �׷���
	Graph(unsigned N) : V(N) {}

	//�׷����� ���� ���� ��ȯ
	auto Vertices() const
	{
		return V;
	}

	//��ü ���� ����Ʈ ��ȯ
	auto& Edges() const
	{
		return edge_list;
	}

	//���� v���� ������ ��� ������ ��ȯ
	auto Edges(unsigned v)const
	{
		vector<Edge<T>> edges_from_v;
		for (auto& e : edge_list)
		{
			if (e.src == v)
				edges_from_v.emplace_back(e);
		}

		return edges_from_v;
	}

	void Add_Edge(Edge<T>&& e)
	{
		//���� �� �� ���� ID�� ��ȿ���� �˻�
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
			edge_list.emplace_back(e);
		else
			cout << "���� : ��ȿ������ ��� ����" << endl;
	}

	//ǥ�� ��� ��Ʈ�� ����
	template<typename U>
	friend ostream& operator<<(ostream& os, const Graph<U>& G)
	{
		for (unsigned i = 1; i < G.Vertices(); i++)
		{
			os << i << ":\t";
			suto edges = G.Edges(i);
			for (auto& e : edges)
				os << "{" << e.dst << ": " << e.weight << "}, ";
			os << endl;
		}
		return os;
	}

private:
	unsigned V;
	vector<Edge<T>> edge_list;
};

unordered_map<unsigned, string> color_map = {
	{1, "Red"},
	{2, "Blue"},
	{3, "Green"},
	{4, "Yellow"},
	{5, "Black"},
	{6, "White"},
};

//�׷��� �÷��� �˰���
template<typename T>
auto Greedy_Coloring(const Graph<T>& G)
{
	auto size = G.Vertices();
	vector<unsigned> assigned_colors(size);

	//1������ ���ʷ� �˻�
	for (unsigned i = 1; i < size; i++)
	{
		auto outgoing_edges = G.Edges(i);

		//i��° ������ ������ �ִ� �������� ���� ����
		set<unsigned> neighbors;
		for (auto& e : outgoing_edges)
		{
			neighbors.insert(assigned_colors[e.dst]);
		}

		//������ ������ ĥ������ ���� �� �� ���� ���� ���� ����
		auto smallest = 1;
		for (; smallet <= color_map.size(); smallest++)
		{
			if (neighbors.find(smallest) == neighbors.end())
				break;
		}

		assigned_colors[i] = smallest;
	}

	return assigned_colors;
}

//���� ���� �˰��� -> ����(����� ������ ��) �� ���� �������� �����ϴ� ��
//1. ��� ������ ������ �������� ����
//2. ���� ���� ù��° ���� ���� -> �� ������ ����� ��� ���� ���� �� ������ ���� �� �Ҵ�