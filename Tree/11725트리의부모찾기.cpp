#include <iostream>


int N;
int parent[100001];


struct Node
{
	int pos;
	Node* first;
	Node* second;
};

struct Tree
{
	Node* root;

	static Tree Create()
	{
		Tree tree;
		tree.root = new Node{ 1, NULL, NULL };
		parent[1] = 0;
		return tree;
	}

	Node* Find(Node* _p, int _c)
	{
		if (_p == NULL) return NULL;

		if (_p->pos == _c) return _p;

		auto first = Tree::Find(_p->first, _c);

		if (first != NULL) return first;

		return Tree::Find(_p->second, _c);
	}

	void Add(int _a, int _b)
	{
		auto a1 = Tree::Find(root, _a);
		auto b1 = Tree::Find(root, _b);

		//숫자하나는 이미 있고 다른 하나는 없다면
		if (a1 != NULL)
		{
			if (a1->first == NULL)
			{
				a1->first = new Node{ _b, NULL, NULL };
				parent[_b] = _a;
				return;
			}

			if (a1->second == NULL)
			{
				a1->second = new Node{ _b, NULL, NULL };
				parent[_b] = _a;
				return;
			}
		}

		if (b1 != NULL)
		{
			if (b1->first == NULL)
			{
				b1->first = new Node{ _a, NULL, NULL };
				parent[_a] = _b;
				return;
			}

			if (b1->second == NULL)
			{
				b1->second = new Node{ _a, NULL, NULL };
				parent[_a] = _b;
				return;
			}
		}
	}
};


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Tree tree = Tree::Create();
	std::cin >> N;

	int a, b;

	for (int i = 0; i < N - 1; i++)
	{
		std::cin >> a >> b;
		tree.Add(a, b);
	}

	for (int i = 2; i < N + 1; i++)
	{
		std::cout << parent[i] << "\n";
	}

	return 0;
}