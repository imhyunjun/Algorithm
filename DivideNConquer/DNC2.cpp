//퀵정렬 -> 실행시간을 줄이는 것이 목표
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
auto Partition(typename vector<T>::iterator _begin, typename vector<T>::iterator _end)
{
	//세개의 반복자 생성
	//하나는 피벗, 나머지 둘은 벡터으 시작과 마지막
	auto pivot_val = *_begin;
	auto left_iter = _begin + 1;
	auto right_iter = _end;

	while (true)
	{
		//벡터의 첫번쨰 원소부터 시작하여 피벗보다 큰 원소를 찾는다
		while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
		{
			left_iter++;
		}

		//벡터의 마지막 원소부터 시작하여 역순으로 피벗보다 작은 원소를 찾음
		while (*right_iter >= pivot_val && distance(left_iter, right_iter) > 0)
		{
			right_iter--;
		}

		//만약 left와 right가 같다면 교환할 원소가 없음
		//그렇지 않으면 lelft와 right의 원소를 서로 교체
		if (left_iter == right_iter) break;
		else
			iter_swap(left_iter, right_iter);
	}

	if (pivot_val > *right_iter)
		iter_swap(_begin, right_iter);

	return right_iter;
}

template<typename T>
auto Quick_Sort(typename vector<T>::iterator _begin, typename vector<T>::iterator _last)
{
	//만약 벡터에 하나 이상의 원소가 있다면
	if (distance(_begin, _last) > 1)
	{
		auto partition_iter = Partition<T>(_begin, _last);
		Quick_Sort<T>(_begin, partition_iter - 1);

		Quick_Sort<T>(partition_iter, _last);
	}
}

template<typename T>
void print_vector(vector<T> arr)
{
	for (auto i : arr)
		cout << i << " ";

	cout << endl;
}

void runc_quick_sort_test()
{
	vector<int> s1{ 45,1,3,1,2,3,45,5,1,2,44,5,7 };
	Quick_Sort<int>(s1.begin(), s1.end() - 1);
	print_vector<int>(s1);
}

int main()
{
	runc_quick_sort_test();
	return 0;
}

//distance랑 iter_swap 버전문제인지 적용이 안됨