#include<iostream>
using namespace std;
long long d[101][10];

long long int go(int n, int l) {
	if (n == 1) {
		if (l == 0) return 0;
		return 1;
	}

	if (d[n][l] > 0) return d[n][l];

	for (int j = 0; j <= 9; j++)
	{
		if (j < 9) d[n][j] += go(n - 1, j + 1);
		if (j > 0) d[n][j] += go(n - 1, j - 1);
		d[n][j] %= 1000000000;
	}
	return d[n][l];
}

long long int result(int n) {
	long long int ret = 0;
	for (int i = 0; i <= 9; i++)
	{
		ret += go(n, i);
	}
	return ret %= 1000000000;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << result(n);
	return 0;
}