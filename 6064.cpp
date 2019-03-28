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
		x -= 1; // 1 ~ m 을 0 ~ m - 1로 바꿔주어 % m 연산을 썼을 때 0부터 반복되도록 바꿔준다.
		y -= 1;
		bool ok = false; //요구조건 충족을 위해
		//int end = lcm(n, m);
		for (int k = x; k < n*m; k += m) { //x를 기준으로 m씩 증가시켜 y를 찾는다.
			if (k%n == y) {
				cout << k + 1 << '\n';
				ok = true; //완료
				break; //끝
			}
		}
		if (!ok) { //답이 없음
			cout << -1 << '\n';
		}
	}
	return 0;
}