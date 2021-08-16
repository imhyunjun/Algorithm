//���� ù ��° ���ҿ��� ���� ����

#include <iostream>
#include <forward_list>

using namespace std;

struct A
{
	int age;
};

ostream& operator<<(ostream& os, const A& c)
{
	return(os << "[" << c.age << "]");
}


void print(forward_list<int> a)
{
	for (const auto& c : a)
		cout << c << "";

	cout << endl;
}

int main()
{

#pragma region �Լ�
	//forward_list<int> a = { 1, 2, 3 };

	////O(1) ����
	//a.push_front(3);
	//cout << a.front();

	//auto it = a.begin();
	//a.insert_after(it, 4);		//�� ó�� ���� �ڿ� 4�߰� ( 3 4 1 2 3)

	////���� O(1)
	//a.pop_front();
	//cout << a.front();

	//it = a.begin();
	//a.erase_after(it);			//�� ���� ���� ���Ҹ� ���� ( 4 2 3)

	////���� O(N) N : ����Ʈ ������
	//a.erase_after(it, a.end());	//�� �� ���� ���� ���� ������ ���Ұ��� ���� ( 4 )
#pragma endregion

#pragma region remove_if
	forward_list<A> as = { {1}, {2}, {3} };
	auto as_copy = as;

	for (const auto& c : as)
		cout << c << "";

	cout << endl;

	as.remove_if([](const A& c)
	{
		return (c.age < 2);
	});

	for (const auto& c : as)
		cout << c << "";

	//����Ʈ ��ü�� ��ȸ -> O(N)
#pragma endregion

#pragma region sort, unique, reverse

	forward_list<int> b = { -1, 0, 35, 3 };

	b.sort();		//O(nlogn)
	print(b);

	b.sort(greater<int>());
	print(b);

	b.reverse();	//O(n)
	print(b);

	b.unique();		//O(n) //������ ���Ҹ� �����ϰ� ���� -> sort�� ��� �ؾ� ��
	print(b);

	
#pragma endregion

	return 0;
}



