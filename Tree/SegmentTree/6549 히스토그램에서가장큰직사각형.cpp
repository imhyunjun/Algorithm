#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Node
{
public:

	Node(bool _isLeaf, int _minIdx, int _startIdx, int _endIdx)
	{
		isLeaf = _isLeaf;
		minIdx = _minIdx;
		startIdx = _startIdx;
		endIdx = _endIdx;
	}

	bool isLeaf;
	int minIdx;
	int startIdx;
	int endIdx;
	Node* leftChild = nullptr;
	Node* rightHild = nullptr;
};

vector<Node*> segTree;
vector<long long> height;
long long answer;

Node* Init(int _idx, int _startIdx, int _endIdx)
{
	if (_startIdx == _endIdx)
	{
		segTree[_idx] = new Node(true, _startIdx, _startIdx, _endIdx);
		return segTree[_idx];
	}

	int mid = (_startIdx + _endIdx) / 2;
	Node* leftNode = Init(2 * _idx + 1, _startIdx, mid);
	Node* rightNode = Init(2 * _idx + 2, mid + 1, _endIdx);

	long long leftHeight = height[leftNode->minIdx];
	long long rightHeight = height[rightNode->minIdx];
	int minIdx = 0;
	if (leftHeight > rightHeight)
	{
		minIdx = rightNode->minIdx;
	}
	else
	{
		minIdx = leftNode->minIdx;
	}
	segTree[_idx] = new Node(false, minIdx, _startIdx, _endIdx);
	segTree[_idx]->leftChild = leftNode;
	segTree[_idx]->rightHild = rightNode;

	return segTree[_idx];
}

int FindMinIdx(Node* _node, int _findStart, int _findEnd)
{
	if (_findStart > _node->endIdx || _findEnd < _node->startIdx) return -1;
	if (_findStart <= _node->startIdx && _findEnd >= _node->endIdx) return _node->minIdx;

	int left, right = -1;

	if (_node->leftChild)
		left = FindMinIdx(_node->leftChild, _findStart, _findEnd);
	if (_node->rightHild)
		right = FindMinIdx(_node->rightHild, _findStart, _findEnd);

	if (left == -1) return right;
	else if (right == -1) return left;
	else return height[left] > height[right] ? right : left;

}

void Solve(int _left, int _right)
{
	if (_left > _right) return;

	int idx = FindMinIdx(segTree[0], _left, _right);
	answer = max(answer, height[idx] * (_right - _left + 1));

	Solve(_left, idx - 1);
	Solve(idx + 1, _right);

}

int main()
{
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		int t_size = (1 << ((int)ceil(log2(N)) + 1)) - 1;

		segTree.resize(t_size);
		height.resize(N);
		answer = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> height[i];
		}

		Init(0, 0, N - 1);
		Solve(0, N - 1);

		cout << answer << "\n";
	}
	return 0;
}