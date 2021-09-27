//병합정렬 분할 후 -> 병합( 대 용량의 데이터 정렬 )

#include <iostream>
#include <vector>

using namespace std;

//두개의 정렬된 벡터를 받아 병합
template<typename T>
vector<T> Merge(vector<T>& arr1, vector<T>& arr2)
{
	vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end())
	{
		if(*iter1 < *iter2)
		{
			merged.emplace_back(*iter1);
			iter1++;
		}
		else
		{
			merged.emplace_back(*iter2);
			iter2++;
		}		
	}

	if (iter1 != arr1.end())
	{
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	if (iter2 != arr2.end())
	{
		for (; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}

	return merged;
}

template<typename T>
vector<T> Merge_Sort(vector<T> arr)
{
	if (arr.size() > 1)
	{
		auto mid = size_t(arr.size() / 2);
		auto left_half = Merge_Sort<T>(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = Merge_Sort<T>(vector<T>(arr.begin() + mid, arr.end()));

		return Merge<T>(left_half, right_half);
	}

	return arr;
}

template<typename T>
void Print_V(vector<T> arr)
{
	for (auto i : arr)
		cout << i << " ";

	cout << endl;
}

int main()
{
	vector<int> s1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };
	vector<float> s2{ 45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 5.5f, 44.0f };
	vector<double> s3{ 45.6, 1.0, 4.8, 1.01, 5.0 };
	vector<char> s4{ 'b', 'z', 'a', 'e', 'c', 't', 'q', 'u', 'y' };

	auto sorted_s1 = Merge_Sort(s1);
	auto sorted_s4 = Merge_Sort(s4);

	Print_V(sorted_s1); cout << endl;
	Print_V(sorted_s4);
	
	return 0;
}