#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define INF 10000000

struct Node
{
	Node(int _to, int _capacity, int _flow = 0)
	{
		to = _to;
		capacity = _capacity;
		flow = _flow;
	}

	Node* reverse = nullptr;
	int capacity = 0;
	int flow = 0;
	int to = 0;
};

vector<vector<Node*>> adj;

void AddNode(int _uin, int _uout, int _vin, int _vout)
{
	//점에서 나가는 것
	Node* uoutvin = new Node(_vin, INF);
	Node* vinuout = new Node(_uout, 0);		//역간선

	uoutvin->reverse = vinuout;
	vinuout->reverse = uoutvin;
	adj[_uout].push_back(uoutvin);
	adj[_vin].push_back(vinuout);

	Node* voutuin = new Node(_uin, INF);
	Node* uinvout = new Node(_vout, 0);		//역간선

	voutuin->reverse = uinvout;
	uinvout->reverse = voutuin;
	adj[_uin].push_back(uinvout);
	adj[_vout].push_back(voutuin);

}

int N, M;
char city[100][100];
bool visited[100][100];

int main()
{
	cin >> N >> M;
	pair<int, int> s = { -1, -1 };
	pair<int, int> t = { -1, -1 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;

			city[i][j] = c;

			if (c == 'K')
			{
				s = { i, j };
			}
			else if (c == 'H')
			{
				t = { i, j };
			}
		}
	}

	if (abs(s.first - t.first) + abs(s.second - t.second) == 1 )
	{
		cout << -1;
		return 0;
	}

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int total = 0;
	int vertex = N * M * 2;
	adj = vector<vector<Node*>>(vertex);

	for (int i = 0; i < vertex; i += 2)
	{
		Node* in_out = new Node(i + 1, 1);
		//out에서 in으로는 간선이 없으므로 역방향의 용량은 0
		Node* out_in = new Node(i, 0);

		//서로를 역방향 간선으로 저장
		in_out->reverse = out_in;
		out_in->reverse = in_out;

		adj[i].push_back(in_out);
		adj[i + 1].push_back(out_in);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (city[i][j] == '#')
			{
				continue;
			}
			visited[i][j] = true;

			int u_in = ((i * M) + j) * 2;
			int u_out = u_in + 1;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				//범위 확인
				if (nx < 0 || N <= nx || ny < 0 || M <= ny)
				{
					continue;
				}

				if (city[nx][ny] == '#')
				{
					continue;
				}

				if (!visited[nx][ny])
				{
					int v_in = ((nx * M) + ny) * 2;
					int v_out = v_in + 1;
					AddNode(u_in, u_out, v_in, v_out);
				}
			}

		}
	}

	int source_out = ((s.first * M) + s.second) * 2 + 1;
	int sink_in = ((t.first * M) + t.second) * 2;

	while (true)
	{
		vector<int> parent(N * M * 2, -1);
		vector<Node*> node(vertex);
		queue<int> q;
		q.push(source_out);
		parent[source_out] = source_out;

		while (!q.empty() && parent[sink_in] == -1)
		{
			int curr = q.front();
			q.pop();

			for (int i = 0; i < adj[curr].size(); i++)
			{
				Node* next = adj[curr][i];
				int to = next->to;
				if (next->capacity - next->flow > 0 && parent[to] == -1)
				{
					q.push(to);
					parent[to] = curr;
					node[to] = next;
					if (to == sink_in) break;
				}
				
			}
		}

		if (parent[sink_in] == -1) break;

		int F = INF;

		for (int i = sink_in; i != source_out; i = parent[i])
		{
			F = min(F, node[i]->capacity - node[i]->flow);
		}

		for (int i = sink_in; i != source_out; i = parent[i])
		{
			node[i]->flow += F;
			node[i]->reverse->flow -= F;
		}

		total += F;
	}

	cout << total;

	return 0;
}