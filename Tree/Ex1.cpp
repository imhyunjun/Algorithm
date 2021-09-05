#include <iostream>
#include <queue>

//����Ʈ�� ����
struct node
{
	std::string position;
	node* first;
	node* second;
};

struct org_tree
{
	node* root;

	//��Ʈ ��� ���� �� �Ѱ�
	static org_tree Create(const std::string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* Find(node* root, const std::string& value)
	{
		if (root == NULL) return NULL;

		if (root->position == value) return root;

		auto firstFound = org_tree::Find(root->first, value);

		if (firstFound != NULL) return firstFound;

		return org_tree::Find(root->second, value);
	}

	bool AddSub(const std::string& manager, const std::string& subord)
	{
		auto managerNode = org_tree::Find(root, manager);

		if (!managerNode)
		{
			std::cout << manager << "��(��) ã�� �� �����ϴ� : " << std::endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " �Ʒ��� " << subord << "��(��) �߰��� �� �����ϴ�. " << std::endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subord, NULL, NULL };
		else
			managerNode->second = new node{ subord, NULL, NULL };

		std::cout << manager << " �Ʒ��� " << subord << "��(��) �߰��Ͽ����ϴ�. " << std::endl;

		return true;

	}
};

//preorder traversal - ���� ��ȸ
static void PreOrder(node* start)
{
	if (!start) return;

	std::cout << start->position << ", ";
	PreOrder(start->first);
	PreOrder(start->second);
}

//in-order traversal - ���� ��ȸ
static void InOrder(node* start)
{
	if (!start) return;

	InOrder(start->first);
	std::cout << start->position << ", ";
	InOrder(start->second);
}

//post-oder traversal - ���� ��ȸ
static void PostOder(node* start)
{
	if (!start) return;

	PostOder(start->first);
	PostOder(start->second);
	std::cout << start->position << ", ";
}

//level order traversal - ���� ���� ��ȸ
static void LevelOrder(node* start)
{
	if (!start) return;

	std::queue<node*> q;
	q.push(start);

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			auto current = q.front();
			q.pop();

			std::cout << current->position << ", ";
			if (current->first)
				q.push(current->first);
			if (current->second)
				q.push(current->second);
		}

		std::cout << std::endl;
	}
}

int main()
{
	auto tree = org_tree::Create("CEO");

	tree.AddSub("CEO", "�λ���");
	tree.AddSub("�λ���", "IT����");
	tree.AddSub("�λ���", "�����ú���");
	tree.AddSub("�λ���", "�۰�������");

	LevelOrder(tree.root);
}