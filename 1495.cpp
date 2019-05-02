#include<iostream>
using namespace std;

bool cache[101][1001];
int v[101];

int main() {
	int n, s, m;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	cache[0][s] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (cache[i - 1][j]) {
				if (j + v[i] <= m) cache[i][j + v[i]] = true;
				if (j - v[i] >= 0) cache[i][j - v[i]] = true;
			}
		}
	}
	for (int j = m; j >= 0; j--)
	{
		if (cache[n][j]) {
			cout << j << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';

	return 0;
}