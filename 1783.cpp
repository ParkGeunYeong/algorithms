#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	if (n == 1) {
		cout << 1;
	}
	else if (n == 2) {
		if (m < 3) cout << 1;
		else if (m < 5) cout << 2;
		else if (m < 7) cout << 3;
		else cout << 4;
	}
	else {
		if (m == 1) cout << 1;
		else if (m == 2) cout << 2;
		else if (m == 3) cout << 3;
		else if (m < 7) cout << 4;
		else cout << 4 + m - 6;
	}

	return 0;
}