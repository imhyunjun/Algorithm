//�ʹ� �ܼ��ؼ� ��� �˰��򿡸� ����
// �Ǵ� -> ���� �κ� ���� �Ӽ�, �׸��� ���� �Ӽ����� �Ǵ�

//�ִ� �۾� �켱 �����ٸ�
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
	cout << " - ó�� �ð� ";
	Print_Vector<T>(service_times);
	cout << " - ��� �ð� ";
	Print_Vector<T>(waiting_times);

	auto ave = accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
	cout << " - ��� ��� �ð� " << ave;

	cout << endl;
}

int main(int argc, char* argv[])
{
	vector<int> service_times{ 8,1,2,3,9,2,4,5 };
	cout << "ó��" << endl;
	Compute_and_Print(service_times);
	//�������� ����
	sort(service_times.begin(), service_times.end());
	cout << "����" << endl;
	Compute_and_Print(service_times);

	return 0;
}