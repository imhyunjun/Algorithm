//������ -> ����ð��� ���̴� ���� ��ǥ
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
auto Partition(typename vector<T>::iterator _begin, typename vector<T>::iterator _end)
{
	//������ �ݺ��� ����
	//�ϳ��� �ǹ�, ������ ���� ������ ���۰� ������
	auto pivot_val = *_begin;
	auto left_iter = _begin + 1;
	auto right_iter = _end;

	while (true)
	{
		//������ ù���� ���Һ��� �����Ͽ� �ǹ����� ū ���Ҹ� ã�´�
		while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
		{
			left_iter++;
		}

		//������ ������ ���Һ��� �����Ͽ� �������� �ǹ����� ���� ���Ҹ� ã��
		while (*right_iter >= pivot_val && distance(left_iter, right_iter) > 0)
		{
			right_iter--;
		}

		//���� left�� right�� ���ٸ� ��ȯ�� ���Ұ� ����
		//�׷��� ������ lelft�� right�� ���Ҹ� ���� ��ü
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
	//���� ���Ϳ� �ϳ� �̻��� ���Ұ� �ִٸ�
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

//distance�� iter_swap ������������ ������ �ȵ�