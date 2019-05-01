#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int cache[1001][1001];
int candy[1001][1001];

int maxCandy(int n, int m) {
	if (n == 1 && m == 1) return candy[1][1];
	if (n < 1 || m < 1) return 0;

	if (cache[n][m] != -1) return cache[n][m];

	cache[n][m] = max(max(maxCandy(n, m - 1), maxCandy(n - 1, m)), maxCandy(n - 1, m - 1)) + candy[n][m];

	return cache[n][m];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> candy[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));

	cout << maxCandy(n, m) << endl;

	return 0;
}