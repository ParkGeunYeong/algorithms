#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring> //string.h --> memset 사용하기 위해

using namespace std;
vector<int> g[1001];
bool check[1001];

int dfs_recursion(int node) {
	if (check[node]) return 0;
	check[node] = true;
	cout << node << ' ';
	for (int i : g[node])
	{
		if (!check[i]) {
			dfs_recursion(i);
		}
	}
	return 0;
}

int dfs_noRecursion(int node) {
	stack<pair<int, int>> s;
	s.push(make_pair(node, 0)); //첫번째를 방문하고 다음 방문할 것을 저장
	check[node] = true;
	cout << node << ' ';
	while (!s.empty()) {
		int node = s.top().first;
		int start = s.top().second;
		s.pop();
		for (int i = start; i < g[node].size(); i++)
		{
			if (!check[g[node][i]]) {
				check[g[node][i]] = true;
				cout << g[node][i] << ' ';
				s.push(make_pair(node, i + 1));
				s.push(make_pair(g[node][i], 0));
				break;
			}
		}
	}
	return 0;
}

int bfs(int node) {
	queue<int> q;
	check[node] = true; q.push(node);
	cout << node << ' ';
	while (!q.empty()) {
		int newNode = q.front();
		q.pop();
		for (int i : g[newNode]) {
			if (!check[i]) {
				check[i] = true; q.push(i);
				cout << i << ' ';
			}
		}
	}
	return 0;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	
	cin >> n >> m >> v;

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		g[temp1].push_back(temp2); g[temp2].push_back(temp1);
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	dfs_noRecursion(v);
	//dfs_recursion(v);
	memset(check, false, sizeof(check)); cout << '\n';
	bfs(v);

	return 0;
}