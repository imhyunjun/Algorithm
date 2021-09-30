//선형 시간 선택 각 단계에서 두개가 아닌 여러개로 분할
#include <iostream>
#include <vector>

using namespace std;

//두 반복자 사이의 중간 값을 찾는 함수 작성
template<typename T>
auto Find_Median(typename vector<T>::iterator begin, typename vector<T>::iterator last)
{
    //정렬
    Quick_Sort<T>(begin, last);

    //중앙값 원소 반복자를 반환
    return begin + distance(begin / last) / 2;
}

template<typename T>
auto Partition_Using_Given_Pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end, typename vector<T>::iterator pivot)
{
    //피벗 위치는 함수 인자로 주어지므로, 벡터의 시작과 마지막 원소를 가리키는 반복자 정의
    auto left_iter = begin;
    auto right_iter = end;

    while(true)
    {
        //벡터의 첫번째 원소부터 시작하여 피벗보다 큰 원소 찾기
        while(*left_iter < *pivot && left_iter != right_iter)
            left_iter++;
        
        //벡터의 마지막 원소부터 역순으로 피벗보다 작은 원소 찾기
        while(*right_iter >= *pivot && left_iter != right_iter)
            right_iter--;
        
        if(left_iter == right_iter) break;
        else iter_swap(left_iter, right_iter);
    }

    if(*pivot > *right_iter)
        iter_swap(pivot, right_iter);

    return right_iter;
}

//선형 시간 검색 알고리즘
template<typename T>
typename vector<T>::iterator Linear_Time_Select(typename vector<T>::iterator begin, typename vector<T>::iterator last, size_t i)
{
    auto size = distance(begin, last);

    if(size > 0 && i < size)
    {
        //다섯개 원소로 구부하여 만들 부분 벡터 Vi 개수 계산
        auto num_Vi = (size + 4 ) / 5;
        size_t j = 0;

        //각각의 VI에서 중앙값을 찾아 벡터 M에 저장
        vector<T> M;
        for(; j < size / 5; j++)
        {
            auto b = begin + (j * 5);
            auto l = begin + (j * 5) + 5;

            M.push_back(*Find_Median<T>(b, l));
            }

        if(j*5 < size)
        {
            auto b = begin + (j * 5);
            auto l = begin + (j * 5) + (size % 5);

            M.push_back(*Find_Median<T>(b, l));
        }

        //Vi의 중앙값으로 구성된 벡터 M에서 다시 중앙값 q를 찾는다
        auto median_of_medians = (M.size == 1) ? M.begin() : Linear_Time_Select<T>(M.begin(), M.end() - 1, M.size() / 2);

        //분할 연산을 적용하고피벗 q의 위치 k를 찾음
        auto partition_iter = Partition_Using_Given_Pivot<T>(begin, last, median_of_medians);
        auto k = distance(begin, partition_iter) + 1;

        if( i == k) return partition_iter;
        else if( i < k) return Linear_Time_Select<T>(begin, partition_iter -1 , i);
        else return Linear_Time_Select<T>(partition_iter + 1, last, i - k);
    }
    else
        return begin;
}

   


int main()
{
    cout << 1 << endl;
    
    return 0;
}