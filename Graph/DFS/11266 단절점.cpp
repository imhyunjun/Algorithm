#include <iostream>
#include <vector>
#include <set>

using namespace std;

int V, E;
vector<int> graph[10001];
set<int> articulation;
int order[10001];

int number = 1;

int DFS(int _current, int _root)
{
	order[_current] = number++;
	int child = 0;
	int fastestNode = order[_current];		//인접한 노드 중 빠른 노드

	for (int i = 0; i < graph[_current].size(); i++)
	{
		int next = graph[_current][i];

		//이미 방문했다면
		if (order[next])
		{
			fastestNode = min(fastestNode, order[next]);
			continue;
		}

		child++;
		int childTime = DFS(next, 0);
		//자식이 갈 수 있는 최대 범위가 자신보다 크거나 같다면(자신보다 빠른 번호로 갈 수 없다면)
		if (!_root && childTime >= order[_current])
		{
			//_current는 단절점
			articulation.insert(_current);
		}

		fastestNode = min(childTime, fastestNode);

	}
	if (_root && child > 1)
	{
		articulation.insert(_current);
	}
	return fastestNode;
}

int main()
{
	cin >> V >> E;

	//그래프 설정
	for (int i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i < V; i++)
	{
		if (!order[i])
		{
			DFS(i, 1);
		}
	}

	int size = articulation.size();
	cout << size << "\n";
	for (int n : articulation)
	{
		cout << n << " ";
	}

	return 0;
}