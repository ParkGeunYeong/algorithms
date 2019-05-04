#include<iostream>
#include<cstring>;
using namespace std;
bool board[33][33];
long long d[3][33][33];


long long go(int s, int r, int c) {
	if (r < 1 || c < 2) return 0;
	if (s == 0 && r == 1 && c == 2) return 1;
	if (board[r][c]) return 0;
	if (s == 2 && (board[r - 1][c] || board[r][c - 1])) return 0;

	long long& ret = d[s][r][c];
	if (ret != -1) return ret;

	if (s == 0) ret = go(0, r, c - 1) + go(2, r, c - 1);
	else if (s == 1) ret = go(1, r - 1, c) + go(2, r - 1, c);
	else ret = go(0, r - 1, c - 1) + go(1, r - 1, c - 1) + go(2, r - 1, c - 1);

	return ret;
}

int main() {
	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << go(0, n, n) + go(1, n, n) + go(2, n, n) << '\n';
	return 0;
}