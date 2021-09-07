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

	//�ļ� ��带 ã�� �Լ� - �ڱ⺸�� ū �����߿� ���� ���� ����
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

		if (_v < _curr->data)		//���ʿ� �ִ� ���
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
			//�ڽ� ��尡 ���� ���ų� ���� �ڽ� ��常 ���� ���
			if (_s->left == NULL)
			{
				auto tmp = _s->right;
				delete _s;
				return tmp;
			}

			//������ �ڽ� ��常 ���� ���
			if (_s->right == NULL)
			{
				auto tmp = _s->left;
				delete _s;
				return tmp;
			}

			//�ڽ� ��尡 �� �� �ִ� ���
			auto succNode = Successor(_s);
			_s->data = succNode->data;

			//������ ���� Ʈ������ �ļ��� ã�Ƽ� ����
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
		cout << "2�� �ֽ��ϴ�. " << endl;

	tree.Insert(20);
	tree.Insert(8);
	tree.Insert(11);
	tree.Insert(15);
	tree.Insert(28);
	tree.Insert(4);
	tree.Insert(2);

	tree.InOrder();	//BST( ���� �˻� Ʈ������ ������ȸ�� �ϸ� �������� )

	cout << endl;

	cout << endl;

	tree.DeleteValue(12);

	if (!tree.Find(12))
		cout << "12�� �����ϴ�. " << endl;



	return 0;
}