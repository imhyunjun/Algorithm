//0-1배낭 문제(일반 배낭 문제) -> NP-완전문제 : 다항 솔루션 사용 X
//하지만 조금 변경한 분할 가능 배낭문제는 그리디로 해결 가능

//분할 가능 배낭문제
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Object
{
	int id;
	int weight;
	double value;
	double value_per_unit_weight;

	Object(int i, int w, double v) : id(i), weight(w), value(v), value_per_unit_weight(v / w) {}

	inline bool operator< (const Object& obj) const
	{
		return this->value_per_unit_weight < obj.value_per_unit_weight;
	}
};

//분할 가능 배날 문제 알고리즘 구현 함수
auto Fill_Knapsack(vector<Object>& objs, int knapsack_capacity)
{
	vector<Object> knapsack_contents;
	knapsack_contents.reserve(objs.size());

	//내림차순 정렬
	sort(objs.begin(), objs.end());
	reverse(objs.begin(), objs.end());

	//가장 가치 있는 물건들 추가
	auto current_obj = objs.begin();
	int current_total_weight = 0;

	while (current_total_weight < knapsack_capacity && current_obj != objs.end())
	{
		knapsack_contents.push_back(*current_obj);
		current_total_weight += current_obj->weight;
		current_obj++;
	}

	//마지막 추가한 물건에 의해 배낭 최대 허용 무게가 초과된 경우
	int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
	Object& last_obj = knapsack_contents.back();
	if (weight_of_last_obj_to_remove > 0)
	{
		last_obj.weight -= weight_of_last_obj_to_remove;
		last_obj.value -= last_obj.value_per_unit_weight * weight_of_last_obj_to_remove;
	}
	return knapsack_contents;
}