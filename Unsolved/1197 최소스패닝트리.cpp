#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V, E;
int weight_sum = 0;

struct Edge
{
	int point1;
	int point2;
	int weight;

	Edge(int _p1, int _p2, int _w) : point1(_p1), point2(_p2), weight(_w) {}

	inline bool operator<(const Edge& _e) const
	{
		return this->weight < _e.weight;
	}

	inline bool operator>(const Edge& _e) const
	{
		return this->weight > _e.weight;
	}
};

vector<Edge> graph;

class DS
{
	struct Node
	{
		int id;
		int rank;
		int parent;

		Node(int _id) : id(_id), rank(0), parent(_id) {}

		inline bool operator !=(const Node& _node) const
		{
			return this->id != _node.id;
		}
	};

	vector<Node> nodes;

public:
	DS(int _N)
	{
		nodes.reserve(_N);
	}

	void Make_Set(const int& _x)
	{
		nodes.emplace_back(_x);
	}

	int Find(int _x)
	{
		auto node = find_if(nodes.begin(), nodes.end(), [_x](auto n) {return n.id == _x; });
		int node_id = (*node).id;

		while (node_id != nodes[node_id].parent)
		{
			node_id = nodes[node_id].parent;
		}

		return node_id;
	}

	void Union(int _x, int _y)
	{
		int root_x = Find(_x);
		int root_y = Find(_y);

		if (root_x == root_y) return;

		if (nodes[root_x].rank > nodes[root_y].rank)
			swap(root_x, root_y);

		nodes[root_x].parent = nodes[root_y].parent;
		nodes[root_y].rank++;
	}
};

void MST()
{
	priority_queue<Edge, vector<Edge>, greater<Edge>> min_heap;

	for (auto& e : graph)
	{
		min_heap.push(e);
	}

	DS ds(V + 1);

	for (int i = 0; i < V + 1; i++)
	{
		ds.Make_Set(i);
	}

	while (!min_heap.empty())
	{
		Edge e = min_heap.top();
		min_heap.pop();

		if (ds.Find(e.point1) != ds.Find(e.point2))
		{
			if (e.point1 >= 1 && e.point1 <= V && e.point2 >= 1 && e.point2 <= V)
			{
				weight_sum += e.weight;
			}

			ds.Union(e.point1, e.point2);
		}
	}
}

int main()
{
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int p1, p2, w;
		cin >> p1 >> p2 >> w;
		graph.emplace_back(p1, p2, w);
	}

	MST();

	cout << weight_sum;

	return 0;
}

//시간초과