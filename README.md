# Algorithm
- std::array
- std::vector
- std::forward_list
- std::list
- 이진 검색 트리 (BST) - 검색 및 삽입 : O(logN)
- 힙(Heap) - 최대 원소 접근 : O(1), 원소 삽입O(logN), 최대 원소 삭제 : O(logN); -> 완전 이진 트리 사용 - 힙 초기화 : 힙 생성 알고리즘 사용 -> O(N)
- 선형 검색 : O(N)
- 퀵 정렬 : O(NlogN) 최악 : O(N^2)
- 디스조인트셋을 사용하지 않는 크루스칼 : O(ElogE) (E:엣지의 개수)
- 디스조인트셋을 사용하는 크루스칼 : O(Ea(V)) ( a : 알파 -> 아커만 함수의 역함수 로그함수보다 느리게 증가)
- 포드-풀커슨 알고리즘 : O((V + E)F) V : vertex, E: edge, F : maxFlow (DFS)
- 에드먼드 카프 알고리즘 : O(V * E^2) (BFS)
- Minimum Vertex Cover -> 이분 그래프로 해결 가능( 쾨닉의 정리)
- Minimum Vertex Cut -> Minimum Vertex Cover을 구할 수 있다.
- 네트워크 플로우에서 최소 컷 = max flow

#더 알아 볼 것
- AVL tree, Red-Black tree
- 다익스트라 최단 경로 알고리즘
- 크루스칼 최소 신장 트리 알고리즘 - 증명(최적부분구조, 그리디 선택)
- 디스조인트 셋( 유니온 파인드 ), 포레스트