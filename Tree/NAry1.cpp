//N항 트리
#include <iostream>
#include <vector>

struct NTree
{
	int data;
	std::vector<NTree*> children;
};

//컴퓨터 파일 시스템, 컴파일러에서 많이 사용