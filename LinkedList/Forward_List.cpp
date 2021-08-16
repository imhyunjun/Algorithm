//오직 첫 번째 원소에만 접근 가능

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

#pragma region 함수
	//forward_list<int> a = { 1, 2, 3 };

	////O(1) 삽입
	//a.push_front(3);
	//cout << a.front();

	//auto it = a.begin();
	//a.insert_after(it, 4);		//맨 처음 원소 뒤에 4추가 ( 3 4 1 2 3)

	////삭제 O(1)
	//a.pop_front();
	//cout << a.front();

	//it = a.begin();
	//a.erase_after(it);			//맨 앞의 다음 원소를 삭제 ( 4 2 3)

	////삭제 O(N) N : 리스트 사이즈
	//a.erase_after(it, a.end());	//맨 앞 원소 다음 부터 마지막 원소가지 삭제 ( 4 )
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

	//리스트 전체를 순회 -> O(N)
#pragma endregion

#pragma region sort, unique, reverse

	forward_list<int> b = { -1, 0, 35, 3 };

	b.sort();		//O(nlogn)
	print(b);

	b.sort(greater<int>());
	print(b);

	b.reverse();	//O(n)
	print(b);

	b.unique();		//O(n) //유일한 원소를 제외하고 제거 -> sort후 사용 해야 함
	print(b);

	
#pragma endregion

	return 0;
}



