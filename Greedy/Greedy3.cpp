//크루스칼 알고리즘
//최적 부분 구조와 그리디 선택 둘다 만족 -> 그리디 사용 가능
//유니온 파인드 혹은 디스조인트 셋 자료구조를 사용

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

//디스조인트-셋 자료구조
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

	//디스조인트 - 셋 포레스트
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

		//만약 루트가 같다면 종료
		if (root_x == root_y) return;

		//작은 랭크의 트리를 큰 랭크의 트리 쪽으로 병합
		if (nodes[root_x].rank > nodes[root_y].rank)
			swap(root_x, root_y);

		nodes[root_x].parent = nodes[root_y].parent;
		nodes[root_y].rank++;
	}
};

//그래프 자료구조 - 에지라스트 방식 사용, 우선 엣지 구조체
template <typename T>
struct Edge
{
	unsigned src;
	unsigned dst;
	T weight;

//엣지 비교는 가중치를 이용
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
	//N개의 정점으로 구성된 그래프
	Graph(unsigned N) : V(N) {}

	//그래프의 정점 개수 반환
	auto Vertices() const
	{
		return V;
	}

	//전체 에지 리스트 반환
	auto& Edges() const
	{
		return edge_list;
	}

	//정점 v에서 나가는 모든 에지를 반환
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
		//에지 양 끝 점점 ID가 유효한지 검사
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
			edge_list.emplace_back(e);
		else
			cout << "에러 : 유효범위를 벗어난 점점" << endl;
	}

	//표준 출력 스트림 지원
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

//크루스칼 최소 신장 트리(Minimum Spanning Tree)
template<typename T>
Graph<T> Minimum_Spanning_Tree(const Graph<T>& G)
{
	//에지 가중치를 이용한 최소 힙 구성
	priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> edge_min_heap;

	//모든 에지를 최소 힙에 추가
	for (auto& e : G.Edges())
		edge_min_heap.push(e);

	//정점 개수에 해당하는 크기의 디스조인트-셋 자료구조 생성 및 초기화
	auto N = G.Vertices();
	SimpleDisjointSet dset(N);
	for (unsigned i = 0; i < N; i++)
		dset.Make_Set(i);

	//디스조인트-셋 자료구조를 이용하여 최소 신장 트리 구하기
	Graph<T> MST(N);
	while (!edge_min_heap.empty())
	{
		//최소 힙에서 최소 가중치 에지를 추출
		auto e = edge_min_heap.top();
		edge_min_heap.pop();

		//선책된 에지가 사이클을 생성하지 않으면 해당 에지를 MST에 추가
		if (dset.Find(e.src) != dset.Find(e.dst))
		{
			MST.Add_Edge(Edge<T>{e.src, e.dst, e.weight});
			dst.union_sets(e.src, e.dst);
		}
	}
	return MST;
}