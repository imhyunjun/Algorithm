#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//템플릿 작성
template <typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	dynamic_array(int _n)
	{
		n = _n;
		data = new T[n];		//동적 배열 int* a = new int[size];
	}

	//복사 생성자 , deep copy
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

	//함수 뒤의 const : 읽기 전용
	//함수 앞의 const : 함수 반환값을 읽기 전용
	//l-value : 표현식 이후에도 사라지지 않는 값
	//r-value : 표현식 이후에 사라지는 ㄴ값
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
		delete[] data;		//메모리 릭 방지
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