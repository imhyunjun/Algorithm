//그래프 컬러링 - 인접한 색은 다르게

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

//그래프 자료구조 - 에지라스트 방식 사용, 우선 엣지 구조체
template <typename T>
struct Edge
{
public:
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

unordered_map<unsigned, string> color_map = {
	{1, "Red"},
	{2, "Blue"},
	{3, "Green"},
	{4, "Yellow"},
	{5, "Black"},
	{6, "White"},
};

//그래프 컬러링 알고리즘
template<typename T>
auto Greedy_Coloring(const Graph<T>& G)
{
	auto size = G.Vertices();
	vector<unsigned> assigned_colors(size);

	//1번부터 차례로 검사
	for (unsigned i = 1; i < size; i++)
	{
		auto outgoing_edges = G.Edges(i);

		//i번째 정점과 인접해 있는 정점들의 현재 색상
		set<unsigned> neighbors;
		for (auto& e : outgoing_edges)
		{
			neighbors.insert(assigned_colors[e.dst]);
		}

		//인접한 정점에 칠해지지 않은 색 중 가장 작은 숫자 선택
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

//웰시 포웰 알고리즘 -> 차수(연결된 에지의 수) 가 높은 정점부터 시작하는 것
//1. 모든 정점을 차수로 내림차순 정렬
//2. 색이 없는 첫번째 정점 선택 -> 이 정점과 연결된 모든 정점 조사 후 사용되지 않은 색 할당