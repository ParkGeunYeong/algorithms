#include<iostream>
using namespace std;
bool d[51][51][51][5];
int A, B, C;
char result[51];

bool go(int a, int b, int c, int p) {
	if (a > A || b > B || c > C) return false;
	if (a + b + c == A + B + C) return true;
	if (d[a][b][c][p]) return false;

	d[a][b][c][p] = true;
	int i = a + b + c + 1;

	if (p == 0) {
		if (go(a + 1, b, c, 0)) { result[i] = 'A';  return true; }
		if (go(a, b + 1, c, 1)) { result[i] = 'B';  return true; }
		if (go(a, b, c + 1, 2)) { result[i] = 'C';  return true; }
	}
	else if (p == 1) {
		if (go(a + 1, b, c, 0)) { result[i] = 'A';  return true; }
		if (go(a, b, c + 1, 2)) { result[i] = 'C';  return true; }
	}
	else if (p == 2) {
		if (go(a + 1, b, c, 3)) { result[i] = 'A';  return true; }
		if (go(a, b + 1, c, 4)) { result[i] = 'B';  return true; }
	}
	else if (p == 3) {
		if (go(a + 1, b, c, 0)) { result[i] = 'A';  return true; }
		if (go(a, b + 1, c, 1)) { result[i] = 'B';  return true; }
	}
	else if (p == 4) {
		if (go(a + 1, b, c, 0)) { result[i] = 'A';  return true; }
	}
	return false;
}


int main() {
	string S;
	cin >> S;
	A = B = C = 0;
	for (char i : S) {
		if (i == 'A') A++;
		else if (i == 'B') B++;
		else C++;
	}
	if (go(0, 0, 0, 0)) for (int i = 1; i <= A + B + C; i++) cout << result[i];
	else cout << -1;
	cout << '\n';
}