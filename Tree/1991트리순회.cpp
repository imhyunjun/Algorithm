#include <stdio.h>
#include <iostream>

int N;

struct Node
{
	char pos;
	Node* first;
	Node* second;
};

struct Tree
{
	Node* root;

	static Tree Create()
	{
		Tree tree;
		tree.root = new Node{ 'A', NULL, NULL };
		return tree;
	}

	Node* Find(Node* _root, char _value)
	{
		if (_root == NULL) return NULL;
		if (_root->pos == _value) return _root;

		auto firstFind = Tree::Find(_root->first, _value);

		if (firstFind != NULL) return firstFind;
		
		return Tree::Find(_root->second, _value);
	}

	void AddSub(char _parent, char _child)
	{
		auto node = Tree::Find(root, _parent);

		if (node->first == NULL)
		{
			node->first = new Node{ _child, NULL, NULL };
			return;
		}

		if (node->second == NULL)
		{
			node->second = new Node{ _child, NULL, NULL };
			return;
		}
		
	}
};

//전위순회
void PreOrder(Node* _start)
{
	if (_start->pos == '.') return;

	//현재 노드 먼저
	std::cout << _start->pos;

	//왼쪽
	PreOrder(_start->first);

	//오른쪽
	PreOrder(_start->second);

}

//중위순회
void InOrder(Node* _start)
{
	if (_start->pos == '.') return;

	//왼쪽 순서 먼저
	InOrder(_start->first);

	//현재
	std::cout << _start->pos;

	//오른쪽 순서
	InOrder(_start->second);
}

//후위순회
void PostOrder(Node* _start)
{
	if (_start->pos == '.') return;

	//왼쪽 순서
	PostOrder(_start->first);
	//오른쪽
	PostOrder(_start->second);
	//현재
	std::cout << _start->pos;
}

int main()
{
	Tree tree = Tree::Create();

	char p, c1, c2;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> p >> c1 >> c2;
			tree.AddSub(p, c1);

			tree.AddSub(p, c2);
	}

	PreOrder(tree.root);
	std::cout << std::endl;

	InOrder(tree.root);
	std::cout << std::endl;

	PostOrder(tree.root);
	std::cout << std::endl;

	return 0;
}