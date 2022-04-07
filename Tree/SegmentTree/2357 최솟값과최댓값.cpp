#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<long long> nums;

class Node
{
public:
	Node(long long _max, long long _min, int _start, int _end)
	{
		max = _max;
		min = _min;
		start = _start;
		end = _end;
	}

	long long max;
	long long min;
	int start;
	int end;
	Node* left = nullptr;
	Node* right = nullptr;
};

vector<Node*> segTree;

Node* Init(int _idx, int _start, int _end)
{
	if (_start == _end)
	{
		segTree[_idx] = new Node(nums[_start], nums[_start], _start, _start);
		return segTree[_idx];
	}

	int mid = (_start + _end) / 2;

	Node* left = Init(2 * _idx + 1, _start, mid);
	Node* right = Init(2 * _idx + 2, mid + 1, _end);

	int max = left->max > right->max ? left->max : right->max;
	int min = left->min > right->min ? right->min : left->min;

	segTree[_idx] = new Node(max, min, _start, _end);
	segTree[_idx]->left = left;
	segTree[_idx]->right = right;

	return segTree[_idx];
}

long long FindMax(Node* _node, int _start, int _end)
{
	if (_start > _node->end || _end < _node->start) return -1;
	if (_start <= _node->start && _node->end <= _end) return _node->max;

	long long left = -1;
	long long right = -1;

	if (_node->left)
		left = FindMax(_node->left, _start, _end);
	if (_node->right)
		right = FindMax(_node->right, _start, _end);

	if (left == -1) return right;
	else if (right == -1) return left;
	else
	{
		return left > right ? left : right;
	}
	
}

long long FindMin(Node* _node, int _start, int _end)
{
	if (_start > _node->end || _end < _node->start) return -1;
	if (_start <= _node->start && _node->end <= _end) return _node->min;

	long long left = -1;
	long long right = -1;

	if (_node->left)
		left = FindMin(_node->left, _start, _end);
	if (_node->right)
		right = FindMin(_node->right, _start, _end);

	if (left == -1) return right;
	else if (right == -1) return left;
	else
	{
		return left < right ? left : right;
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	nums.resize(N);

	int t_size = (1 << ((int)ceil(log2(N)) + 1)) - 1;
	segTree.resize(t_size);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	Init(0, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << FindMin(segTree[0], x - 1, y - 1) << " " << FindMax(segTree[0], x - 1, y - 1) << "\n";
	}



	return 0;
}