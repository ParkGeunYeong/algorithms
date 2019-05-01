#include<iostream>
using namespace std;
long long d[91][2];

long long go(int n, int l) {
	if (n == 1)
		if (l == 1)return 1;
		else return 0;
	if (d[n][l] > 0) return d[n][l];
	if (l == 0) return d[n][0] = go(n - 1, 0) + go(n - 1, 1);
	if (l == 1) return d[n][1] = go(n - 1, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << go(n, 0) + go(n, 1);
	return 0;
}