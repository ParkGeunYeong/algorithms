#include <iostream>
using namespace std;

//int gcd(int k, int l) { return l ? gcd(l, k%l) : k; }
//int lcm(int k, int l) { return k / gcd(k, l)*l; }

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x -= 1; // 1 ~ m �� 0 ~ m - 1�� �ٲ��־� % m ������ ���� �� 0���� �ݺ��ǵ��� �ٲ��ش�.
		y -= 1;
		bool ok = false; //�䱸���� ������ ����
		//int end = lcm(n, m);
		for (int k = x; k < n*m; k += m) { //x�� �������� m�� �������� y�� ã�´�.
			if (k%n == y) {
				cout << k + 1 << '\n';
				ok = true; //�Ϸ�
				break; //��
			}
		}
		if (!ok) { //���� ����
			cout << -1 << '\n';
		}
	}
	return 0;
}