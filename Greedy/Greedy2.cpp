//0-1�賶 ����(�Ϲ� �賶 ����) -> NP-�������� : ���� �ַ�� ��� X
//������ ���� ������ ���� ���� �賶������ �׸���� �ذ� ����

//���� ���� �賶����
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

//���� ���� �賯 ���� �˰��� ���� �Լ�
auto Fill_Knapsack(vector<Object>& objs, int knapsack_capacity)
{
	vector<Object> knapsack_contents;
	knapsack_contents.reserve(objs.size());

	//�������� ����
	sort(objs.begin(), objs.end());
	reverse(objs.begin(), objs.end());

	//���� ��ġ �ִ� ���ǵ� �߰�
	auto current_obj = objs.begin();
	int current_total_weight = 0;

	while (current_total_weight < knapsack_capacity && current_obj != objs.end())
	{
		knapsack_contents.push_back(*current_obj);
		current_total_weight += current_obj->weight;
		current_obj++;
	}

	//������ �߰��� ���ǿ� ���� �賶 �ִ� ��� ���԰� �ʰ��� ���
	int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
	Object& last_obj = knapsack_contents.back();
	if (weight_of_last_obj_to_remove > 0)
	{
		last_obj.weight -= weight_of_last_obj_to_remove;
		last_obj.value -= last_obj.value_per_unit_weight * weight_of_last_obj_to_remove;
	}
	return knapsack_contents;
}