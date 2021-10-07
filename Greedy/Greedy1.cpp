//너무 단순해서 몇몇 알고리즘에만 적용
// 판단 -> 최적 부분 구조 속성, 그리디 선택 속성으로 판단

//최단 작업 우선 스케줄링
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
auto Compute_Waiting_Times(vector<T>& service_times)
{
	vector<T> w(service_times.size());
	w[0] = 0;

	for (auto i = 1; i < service_times.size(); i++)
		w[i] = w[i - 1] + service_times[i - 1];

	return w;
}

template<typename T>
void Print_Vector(vector<T>& v)
{
	for (auto& i : v)
	{
		cout.width(2);
		cout << i << " ";
	}

	cout << endl;
}

template<typename T>
void Compute_and_Print(vector<T>& service_times)
{
	auto waiting_times = Compute_Waiting_Times<int>(service_times);
	cout << " - 처리 시간 ";
	Print_Vector<T>(service_times);
	cout << " - 대기 시간 ";
	Print_Vector<T>(waiting_times);

	auto ave = accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
	cout << " - 평균 대기 시간 " << ave;

	cout << endl;
}

int main(int argc, char* argv[])
{
	vector<int> service_times{ 8,1,2,3,9,2,4,5 };
	cout << "처음" << endl;
	Compute_and_Print(service_times);
	//오름차순 정렬
	sort(service_times.begin(), service_times.end());
	cout << "나중" << endl;
	Compute_and_Print(service_times);

	return 0;
}