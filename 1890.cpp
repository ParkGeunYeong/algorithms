#include <iostream>
#include <cstring>
using namespace std;

long long cache[101][101];
int board[101][101];

long long go(int n, int m) {
	if (n == 1 && m == 1) return 1;
	if (n < 1 || m < 1) return 0;

	long long& ret = cache[n][m];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i < n; i++)
	{
		if (board[n - i][m] == i) {
			ret += go(n - i, m);
		}
	}
	for (int j = 1; j < m; j++)
	{
		if (board[n][m - j] == j) {
			ret += go(n, m - j);
		}
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << go(n, n);

	return 0;
}