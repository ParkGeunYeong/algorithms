#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> g[20001];
int check[20001];
bool ans = true;

void dfs_color(int color, int node) {
//	if (!ans) return;
	check[node] = color;
	for (int i : g[node]) {
		if (check[i] == 0) {
			dfs_color(3 - color, i);
		}
		else if (check[i] == check[node]) {
			ans = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n, v, t1, t2;
	cin >> k;
	while (k--) {
		cin >> n >> v;
		for (int i = 0; i < v; i++)
		{
			cin >> t1 >> t2;
			g[t1].push_back(t2); g[t2].push_back(t1);
		}
		memset(check, 0, sizeof(check));
		dfs_color(1, t1);
		for (int i = 1; i <= n; i++)
		{
			g[i].clear();
		}
		cout << (ans ? "YES" : "NO") << "\n";
		ans = true;
	}

	return 0;
}