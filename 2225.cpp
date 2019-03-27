#include <iostream>
#include <algorithm>
using namespace std;
int d[201][201];
long long mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n;
	cin >> k;
	d[0][0] = 1; // 0을 0개로 만든다는 방법.
	for (int i = 1; i <= k; i++) { //k개로 만듬
		for (int j = 0; j <= n; j++) { //n의 숫자를
			for (int q = 0; q <= j; q++) { // n(j) 까지의 합
				d[i][j] += d[i - 1][j - q];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[k][n] << '\n';
	return 0;
}