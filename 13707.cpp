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
	d[0][0] = 1; // 0�� 0���� ����ٴ� ���.
	for (int i = 1; i <= k; i++) { //k���� ����
		for (int j = 0; j <= n; j++) { //n�� ���ڸ�
			d[i][j] = d[i - 1][j]; //n�� k-1���� ����� �� +
			if (j - 1 >= 0) {  //d[i][-1]�� ���ϱ� ����
				d[i][j] += d[i][j - 1]; //n-1�� k���� ����� ���� ����
			}
			d[i][j] %= mod;

		}
	}
	cout << d[k][n] << '\n';
	return 0;
}