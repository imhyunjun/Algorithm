//맵 리듀스
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

//f(x) = x ^2
void Transform_Test(vector<int> S)
{
    vector<int> Tr;
    for(auto i : S)
        cout << i << " ";

    //transform 함수 사용
    transform(S.begin(), S.end(), back_inserter(Tr), [](int x) {return pow(x, 2.0);});

    //foreach함수 사용
    for_each(S.begin(), S.end(), [](int& x){x = pow(x, 2.0);});
}

//리듀스 연산 함수
void Reduce_Test(vector<int> S)
{
    auto ans = accumulate(S.begin(), S.end(), 0, [](int acc, int x) {return acc + x;});
}