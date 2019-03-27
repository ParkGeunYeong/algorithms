#include <iostream>
#include <vector>
using namespace std;
bool check[2001];
vector<int> a[2001];
bool ans;
int depth;

void dfs(int x, int d) {
	check[x] = true;
	//printf("%d--%d\n", x,d);
	if (d == 4) ans = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y,d+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	int n1, n2;
	for (int i = 0; i < e; i++) { // 그래프 만들기
		cin >> n1 >> n2;
		//인접리스트의 경우
		a[n1].push_back(n2); a[n2].push_back(n1);
	}
	for (int i = 0; i < v; i++)
	{
		depth = 0;
		//cout << "\n-----" << i << "------\n";
		dfs(i, depth);
		fill_n(check, v, false);
	}
	
	if (ans) cout << 1;
	else cout << 0;

	return 0;
}