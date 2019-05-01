#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long d[100001][3];
int a[100001][2];

long long go(int n, int l) {
	if (n == 1)
		if (l == 0) return 0;
		else if (l == 1) return a[1][0];
		else if (l == 2) return a[1][1];

	if (d[n][l] != -1) return d[n][l];

	if (l == 0) return d[n][0] = max(max(go(n - 1, 0), go(n - 1, 1)), go(n - 1, 2));
	if (l == 1) return d[n][1] = max(go(n - 1, 0), go(n - 1, 2)) + a[n][0];
	if (l == 2) return d[n][2] = max(go(n - 1, 0), go(n - 1, 1)) + a[n][1];
}

long long result(int n) {
	return max(max(go(n, 0), go(n, 1)), go(n, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		memset(d, -1, sizeof(d));
		cin >> n;
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[j][i];

		cout << result(n) << "\n";
	}
	return 0;
}