//ũ�罺Į �˰���
//���� �κ� ������ �׸��� ���� �Ѵ� ���� -> �׸��� ��� ����
//���Ͽ� ���ε� Ȥ�� ������Ʈ �� �ڷᱸ���� ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

//������Ʈ-�� �ڷᱸ��
class SimpleDisjointSet
{
private:
	struct Node
	{
		unsigned id;
		unsigned rank;
		unsigned parent;

		Node(unsigned _id) : id(_id), rank(0), parent(_id) {}

		bool operator != (const Node& _n) const
		{
			return this->id != _n.id;
		}
	};

	//������Ʈ - �� ������Ʈ
	vector<Node> nodes;

public:
	SimpleDisjointSet(unsigned _N)
	{
		nodes.reserve(_N);
	}

	void Make_Set(const unsigned& _x)
	{
		nodes.emplace_back(_x);
	}

	unsigned Find(unsigned _x)
	{
		auto node_it = find_if(nodes.begin(), nodes.end(), [_x](auto n) {return n.id == _x; });
		unsigned node_id = (*node_it).id;

		while (node_id != nodes[node_id].parent)
		{
			node_id = nodes[node_id].parent;
		}

		return node_id;
	}

	void Union_Sets(unsigned _x, unsigned _y)
	{
		auto root_x = Find(_x);
		auto root_y = Find(_y);

		//���� ��Ʈ�� ���ٸ� ����
		if (root_x == root_y) return;

		//���� ��ũ�� Ʈ���� ū ��ũ�� Ʈ�� ������ ����
		if (nodes[root_x].rank > nodes[root_y].rank)
			swap(root_x, root_y);

		nodes[root_x].parent = nodes[root_y].parent;
		nodes[root_y].rank++;
	}
};

//�׷��� �ڷᱸ�� - ������Ʈ ��� ���, �켱 ���� ����ü
template <typename T>
struct Edge
{
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

//ũ�罺Į �ּ� ���� Ʈ��(Minimum Spanning Tree)
template<typename T>
Graph<T> Minimum_Spanning_Tree(const Graph<T>& G)
{
	//���� ����ġ�� �̿��� �ּ� �� ����
	priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> edge_min_heap;

	//��� ������ �ּ� ���� �߰�
	for (auto& e : G.Edges())
		edge_min_heap.push(e);

	//���� ������ �ش��ϴ� ũ���� ������Ʈ-�� �ڷᱸ�� ���� �� �ʱ�ȭ
	auto N = G.Vertices();
	SimpleDisjointSet dset(N);
	for (unsigned i = 0; i < N; i++)
		dset.Make_Set(i);

	//������Ʈ-�� �ڷᱸ���� �̿��Ͽ� �ּ� ���� Ʈ�� ���ϱ�
	Graph<T> MST(N);
	while (!edge_min_heap.empty())
	{
		//�ּ� ������ �ּ� ����ġ ������ ����
		auto e = edge_min_heap.top();
		edge_min_heap.pop();

		//��å�� ������ ����Ŭ�� �������� ������ �ش� ������ MST�� �߰�
		if (dset.Find(e.src) != dset.Find(e.dst))
		{
			MST.Add_Edge(Edge<T>{e.src, e.dst, e.weight});
			dst.union_sets(e.src, e.dst);
		}
	}
	return MST;
}