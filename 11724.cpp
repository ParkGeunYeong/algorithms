#include <iostream>
#include <vector>
using namespace std;
vector<int> g[1001];
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

	int n, v, from, to;
	cin >> n >> v;
	for (int i = 0; i < v; i++)
	{
		cin >> from >> to;
		g[from].push_back(to); g[to].push_back(from);
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