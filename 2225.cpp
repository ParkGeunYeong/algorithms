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
	d[0][0] = 1; // 0�� 0���� ����ٴ� ���.
	for (int i = 1; i <= k; i++) { //k���� ����
		for (int j = 0; j <= n; j++) { //n�� ���ڸ�
			for (int q = 0; q <= j; q++) { // n(j) ������ ��
				d[i][j] += d[i - 1][j - q];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[k][n] << '\n';
	return 0;
}