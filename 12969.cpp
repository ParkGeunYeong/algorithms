#include<iostream>
using namespace std;
int N, K;
bool d[31][31][31][436];
char result[30];

bool go(int a, int b, int c, int k) {
	if (a + b + c == N)
		if (k == K) return true;
		else return false;

	if (d[a][b][c][k]) return false;

	int i = a + b + c;
	d[a][b][c][k] = true;
	
	if (go(a + 1, b, c, k)) {
		result[i] = 'A';
		return true;
	}

	if (go(a, b + 1, c, k + a)) {
		result[i] = 'B';
		return true;
	}
	
	if (go(a, b, c + 1, k + a + b)) {
		result[i] = 'C';
		return true;
	}

	return false;
}

int main() {
	cin >> N >> K;
	if (go(0, 0, 0, 0)) for (int i = 0; i < N; i++) cout << result[i];
	else cout << -1;
	cout << '\n';
	return 0;
}