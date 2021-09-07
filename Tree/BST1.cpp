#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

struct BST
{
	Node* root = nullptr;

	Node* Find(int _v)
	{
		return Find_Imp(root, _v);
	}

public:
	void Insert(int _v)
	{
		if (root == NULL)
		{
			root = new Node{ _v, NULL, NULL };
			cout << "root is null" << endl;
		}
		else
		{
			cout << "root isn't null" << endl;
			Insert_Imp(root, _v);
		}
	}

	void InOrder()
	{
		InOrder_Imp(root);
	}

	//후손 노드를 찾는 함수 - 자기보다 큰 숫자중에 제일 작은 숫자
	Node* Successor(Node* _s)
	{
		auto curr = _s->right;
		while (curr != NULL && curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}

	void DeleteValue(int _v)
	{
		root = Delete_Imp(root, _v);
	}

private:
	Node* Find_Imp(Node* _curr, int _v)
	{
		if (_curr == NULL)
		{
			cout << endl; return NULL;
		}

		if (_curr->data == _v)
		{
			return _curr;
		}

		if (_v < _curr->data)		//왼쪽에 있는 경우
		{
			return Find_Imp(_curr->left, _v);
		}

		return Find_Imp(_curr->right, _v);
	}

	void Insert_Imp(Node* _curr, int _v)
	{
		if (_v < _curr->data)
		{
			if (_curr->left == NULL)
			{
				_curr->left = new Node{ _v, NULL, NULL };
			}
			else
				Insert_Imp(_curr->left, _v);
		}
		else
		{
			if (_curr->right == NULL)
			{
				_curr->right = new Node{ _v, NULL, NULL };
			}
			else
				Insert_Imp(_curr->right, _v);
		}
	}

	void InOrder_Imp(Node* _s)
	{
		if (_s == NULL)
		{
			return;
		}

		InOrder_Imp(_s->left);

		cout << _s->data << ", ";

		InOrder_Imp(_s->right);
	}

	Node* Delete_Imp(Node* _s, int _v)
	{
		if (_s == NULL) return NULL;

		if (_v < _s->data)
			_s->left = Delete_Imp(_s->left, _v);
		else if (_v > _s->data)
			_s->right = Delete_Imp(_s->right, _v);
		else
		{
			//자식 노드가 전혀 없거나 왼쪽 자식 노드만 없는 경우
			if (_s->left == NULL)
			{
				auto tmp = _s->right;
				delete _s;
				return tmp;
			}

			//오른쪽 자식 노드만 없는 경우
			if (_s->right == NULL)
			{
				auto tmp = _s->left;
				delete _s;
				return tmp;
			}

			//자식 노드가 둘 다 있는 경우
			auto succNode = Successor(_s);
			_s->data = succNode->data;

			//오른쪽 서브 트리에서 후속을 찾아서 삭제
			_s->right = Delete_Imp(_s->right, succNode->data);
		}

		return _s;
	}
};

int main()
{
	BST tree;

	tree.Insert(12);
	tree.Insert(10);

	if (tree.Find(10))
		cout << "2가 있습니다. " << endl;

	tree.Insert(20);
	tree.Insert(8);
	tree.Insert(11);
	tree.Insert(15);
	tree.Insert(28);
	tree.Insert(4);
	tree.Insert(2);

	tree.InOrder();	//BST( 이진 검색 트리에서 중위순회를 하면 오름차순 )

	cout << endl;

	cout << endl;

	tree.DeleteValue(12);

	if (!tree.Find(12))
		cout << "12가 없습니다. " << endl;



	return 0;
}