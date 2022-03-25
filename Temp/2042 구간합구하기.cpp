#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Node
{
public: 
	Node(int _idx, int _start, int _end, long long _sum, bool _isleaf = false)
	{
		idx = _idx;
		start = _start;
		end = _end;
		sum = _sum;
		isLeaf = _isleaf;
	}

	int idx;
	int start;
	int end;
	long long sum;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	bool isLeaf;
};

vector<Node*> tree;
vector<long long> input;

Node* Init(int _node, int _start, int _end)
{
	if (_start == _end)
	{
		tree[_node] = new Node(_node, _start, _end, input[_start], true);
		return tree[_node];
	}

	int mid = (_start + _end) / 2;	
	Node* left = Init(_node * 2 + 1, _start, mid);
	Node* right = Init(_node * 2 + 2, mid + 1, _end);

	tree[_node] = new Node(_node, _start, _end, left->sum + right->sum);
	tree[_node]->leftChild = left;
	tree[_node]->rightChild = right;

	return tree[_node];

}

long long Sum(Node* _node, int _start, int _end)
{
	if (_node->start > _end || _node->end < _start) return 0;
	if (_start <= _node->start && _node->end <= _end) return _node->sum;

	long long left = 0;
	long long right = 0;

	if(_node->leftChild)
		left = Sum(_node->leftChild, _start, _end);
	if(_node->rightChild)
		right = Sum(_node->rightChild, _start, _end);

	return left + right;
}

void ChangeNum(Node* _node, int _idx, long long _change)
{
	if (_idx < _node->start || _idx > _node->end) return;

	_node->sum = _node->sum + _change - input[_idx];

	if (_node->isLeaf) return;

	if(_node->leftChild)
		ChangeNum(_node->leftChild, _idx, _change);
	if(_node->rightChild)
		ChangeNum(_node->rightChild, _idx, _change);

	return;
}

int main()
{

	int N, M, K;
	cin >> N >> M >> K;

	int t_size = (1 << ((int)ceil(log2(N)) + 1)) - 1;
	tree.resize(t_size);
	input.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	Init(0, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			ChangeNum(tree[0], b - 1, c);
			input[b - 1] = c;
		}
		else if (a == 2)
		{
			cout << Sum(tree[0], b - 1, c - 1) << "\n";
		}
	}

	

	return 0;
}