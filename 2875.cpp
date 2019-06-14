#include<iostream>
using namespace std;
int main() {
	int n, m, k, team, rest = 0, need = 0;
	cin >> n >> m >> k;

	if (n / 2 > m) {
		team = m;
		rest = n - m * 2;
	}
	else {
		team = n / 2;
		if (n % 2 == 1) rest = m - n / 2 + 1;
		else rest = m - n / 2;
	}
	need = k - rest;
	if (need < 0) {
		cout << team;
		return 0;
	}
	team -= need / 3;
	if (need % 3 != 0) team--;

	if (team < 0) cout << 0;
	else cout << team;

	return 0;
}