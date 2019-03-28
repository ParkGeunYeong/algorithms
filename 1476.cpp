#include<iostream>
using namespace std;
int main() {
	int e, s, m, ans = 0;
	cin >> e >> s >> m;
	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;
	while (1) {
		ans++;
		if (ans % 15 == e && ans % 28 == s && ans % 19 == m) {
			cout << ans << '\n';
			break;
		}
	}
	return 0;
}