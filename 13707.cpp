#include <iostream>
#include <algorithm>
using namespace std;
long long d[5001][5001];
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
			d[i][j] = d[i - 1][j]; //n을 k-1개로 만드는 것 +
			if (j - 1 >= 0) {  //d[i][-1]을 피하기 위해
				d[i][j] += d[i][j - 1]; //n-1을 k개로 만드는 것을 더함
			}
			d[i][j] %= mod;

		}
	}
	cout << d[k][n] << '\n';
	return 0;
}