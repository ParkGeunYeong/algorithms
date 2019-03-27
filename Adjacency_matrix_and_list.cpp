/*
그래프의 표현
인접행렬 - 행렬을 통해 그래프를 표현

	2차원 배열을 통해 그래프를 표현한다.
	정점의 개수를 V 라고 했을 때 V*V 크기의 배열을 사용한다.

	특징 -
	공간은 V*V의 크기를 가진다.
	정점간의 연결을 파악할 때 O(1)로 구할 수 있다.
	정점 X와 연결된 모든 정점은 O(V)로 구할 수 있다.

인접리스트 - 리스트를 사용하여 그래프를 표현한다.

	링크드 리스트나 길이를 동적으로 사용할 수 있는 배열(Vector) 을 통해 표현한다.
	간선의 개수를 E 라고 했을 때 E의 크기를 가진다.

	특징 -
	공간은 2*E의 크기를 가진다.
	정점간의 연결을 파악할 때 O(한쪽 정점의 차수)로 구할 수 있다.
	정점 X와 연결된 모든 정점은 O(X의 차수)로 구할 수 있다.
*/

//정점(5 ≤ V ≤ 2000)과 간선(1 ≤ E ≤ 2000)의 개수와 정점들이 
//어떻게 연결되어 있는지 주어졌을 때 인접행렬, 인접리스트 방식으로 저장 후 출력해보기
/* 입력 예시
4 5
1 2
1 3
1 4
2 4
3 4
*/
#include <iostream>
#include <vector>
using namespace std;
bool am[2001][2001];
//vector<int> al[2001]; 이렇게 선언하고 추가해도 됨.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	vector<vector<int>> al(v + 1);
	int a, b;
	for (int i = 0; i < e; i++) { // 그래프 만들기
		cin >> a >> b;
		//인접행렬의 경우
		am[a][b] = am[b][a] = true;
		//인접리스트의 경우
		al[a].push_back(b); al[b].push_back(a);
	}
	
	//인접 행렬 출력 O(v*v)
	for (int i = 1; i <= v; i++) {
		cout << i << "와 연결된 정점 : ";
		for (int j = 1; j <= v; j++) {
			if (am[i][j]) {
				cout << j << ' ';
			}
		}
		cout << '\n';
	}
	//인접 리스트 출력 o(v+e)
	for (int i = 1; i <= v; i++) {
		cout << i << "와 연결된 정점 : ";
		int al_size = al[i].size();
		for (int j = 0; j < al_size; j++) {
				cout << al[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}