#include <iostream>
#include <queue>

//이진트리 생성
struct node
{
	std::string position;
	node* first;
	node* second;
};

struct org_tree
{
	node* root;

	//루트 노드 생성 단 한개
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
			std::cout << manager << "을(를) 찾을 수 없습니다 : " << std::endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " 아래에 " << subord << "을(를) 추가할 수 없습니다. " << std::endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subord, NULL, NULL };
		else
			managerNode->second = new node{ subord, NULL, NULL };

		std::cout << manager << " 아래에 " << subord << "을(를) 추가하였습니다. " << std::endl;

		return true;

	}
};

//preorder traversal - 전위 순회
static void PreOrder(node* start)
{
	if (!start) return;

	std::cout << start->position << ", ";
	PreOrder(start->first);
	PreOrder(start->second);
}

//in-order traversal - 중위 순회
static void InOrder(node* start)
{
	if (!start) return;

	InOrder(start->first);
	std::cout << start->position << ", ";
	InOrder(start->second);
}

//post-oder traversal - 후위 순회
static void PostOder(node* start)
{
	if (!start) return;

	PostOder(start->first);
	PostOder(start->second);
	std::cout << start->position << ", ";
}

//level order traversal - 레벨 순서 순회
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

	tree.AddSub("CEO", "부사장");
	tree.AddSub("부사장", "IT부장");
	tree.AddSub("부사장", "마케팅부장");
	tree.AddSub("부사장", "앱개발팀장");

	LevelOrder(tree.root);
}