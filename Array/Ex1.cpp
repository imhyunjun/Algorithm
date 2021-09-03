#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//���ø� �ۼ�
template <typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	dynamic_array(int _n)
	{
		n = _n;
		data = new T[n];		//���� �迭 int* a = new int[size];
	}

	//���� ������ , deep copy
	dynamic_array(const dynamic_array<T>& _other)
	{
		n = _ohter.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
			data[i] = _other[i];
	}

	T& operator[](int _idx)
	{
		return data[_idx];
	}

	//�Լ� ���� const : �б� ����
	//�Լ� ���� const : �Լ� ��ȯ���� �б� ����
	//l-value : ǥ���� ���Ŀ��� ������� �ʴ� ��
	//r-value : ǥ���� ���Ŀ� ������� ����
	const T& operator[](int _idx) const
	{
		return data[_idx];
	}

	T& at(int _idx)
	{
		if (_idx < n)
			return data[_idx];
		throw "Index out of range";
	}

	size_t size() const
	{
		return n;
	}

	~dynamic_array()
	{
		delete[] data;		//�޸� �� ����
	}

	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }
};

int main()
{
	int a = 1;
	int& b = a;

	cout << b;

	return 0;
}