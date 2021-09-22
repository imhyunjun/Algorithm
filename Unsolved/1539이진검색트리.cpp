#include <iostream>

using namespace std;

int N;
int P[250000];
int sum = 0;

struct Node
{
	int data;
	int distance;
	Node* first;
	Node* second;
};

struct Tree
{
	Node* root = new Node{ P[0], 0, NULL, NULL };

	void Insert(Node* _root, int _v)
	{
		//삽입하려는 것이 현재의 값보다 크다면
		if (_root->data < _v)
		{
			if (_root->second == NULL)
			{
				_root->second = new Node{ _v, _root->distance + 1, NULL, NULL };
				sum += _root->second->distance;
			}
			else
			{
				Insert(_root->second, _v);
			}
		}
		else
		{
			if (_root->first == NULL)
			{
				_root->first = new Node{ _v, _root->distance + 1, NULL, NULL };
				sum += _root->first->distance;
			}
			else
			{
				Insert(_root->first, _v);
			}
		}
	}
};

int main()
{

	cin >> N;
	cin >> P[0];

	Tree tree;
	for (int i = 1; i < N; i++)
	{
		cin >> P[i];

		tree.Insert(tree.root, P[i]);
	}


	cout << sum + N;

	return 0;
}

//시간 초과 다음에 다른 방법으로 풀어보기 20210907