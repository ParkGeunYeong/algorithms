#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> g;
bool check[1001];

void dfs(int node) {
	if (check[node]) return;
	check[node] = true;
	for (int i : g[node]) {
		if (!check[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, v, t1, t2;
	cin >> n >> v;
	g.assign(n + 1, {});
	for (int i = 0; i < v; i++)
	{
		cin >> t1 >> t2;
		g[t1].push_back(t2); g[t2].push_back(t1);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!check[i]) {
			dfs(i); ans++;
		}
	}
	cout << ans;

	return 0;
}