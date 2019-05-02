#include<iostream>
using namespace std;
long long cache[101][21];
int v[101];

int main() {
	int n, s, l;
	cin >> n >> s;
	n -= 2;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	cin >> l;
	cache[0][s] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 20; j++)
			if (cache[i - 1][j] > 0) {
				if (j + v[i] <= 20) cache[i][j + v[i]] += cache[i - 1][j];
				if (j - v[i] >= 0) cache[i][j - v[i]] += cache[i - 1][j];
			}
	cout << cache[n][l] << '\n';
	return 0;
}