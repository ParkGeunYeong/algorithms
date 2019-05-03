#include<iostream>
#include<cstring>
using namespace std;
int d[51][51][51][5];
int A, B, C;
char result[51];

bool go(int a, int b, int c, int p) {
	if (a > A || b > B || c > C) return 0;
	if (a + b + c == A + B + C) return 1;
	if (d[a][b][c][p] != -1 )return d[a][b][c][p];

	int i = a + b + c;
	if (p == 0) {
		d[a + 1][b][c][p] = true;
		if (go(a + 1, b, c, 0)) { result[i + 1] = 'A';  return true; }
		d[a + 1][b][c][p] = false;
		d[a][b + 1][c][p] = true;
		if (go(a, b + 1, c, 1)) { result[i + 1] = 'B';  return true; }
		d[a][b + 1][c][p] = false;
		d[a][b][c + 1][p] = true;
		if (go(a, b, c + 1, 2)) { result[i + 1] = 'C';  return true; }
		d[a][b][c + 1][p] = false;
	}
	else if (p == 1) {
		d[a + 1][b][c][p] = true;
		if (go(a + 1, b, c, 0)) { result[i + 1] = 'A';  return true; }
		d[a + 1][b][c][p] = false;
		d[a][b][c + 1][p] = true;
		if (go(a, b, c + 1, 2)) { result[i + 1] = 'C';  return true; }
		d[a][b][c + 1][p] = false;
	}
	else if (p == 2) {
		d[a + 1][b][c][p] = true;
		if (go(a + 1, b, c, 3)) { result[i + 1] = 'A';  return true; }
		d[a + 1][b][c][p] = false;
		d[a][b + 1][c][p] = true;
		if (go(a, b + 1, c, 4)) { result[i + 1] = 'B';  return true; }
		d[a][b + 1][c][p] = false;
	}
	else if (p == 3) {
		d[a + 1][b][c][p] = true;
		if (go(a + 1, b, c, 0)) { result[i + 1] = 'A';  return true; }
		d[a + 1][b][c][p] = false;
		d[a][b + 1][c][p] = true;
		if (go(a, b + 1, c, 1)) { result[i + 1] = 'B';  return true; }
		d[a][b + 1][c][p] = false;
	}
	else if (p == 4) {
		d[a + 1][b][c][p] = true;
		if (go(a + 1, b, c, 0)) { result[i + 1] = 'A';  return true; }
		d[a + 1][b][c][p] = false;
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
	memset(d, -1, sizeof(d));
	if (go(0, 0, 0, 0)) {
		for (int i = 1; i <= A + B + C; i++)
		{
			cout << result[i];
		}
		cout << '\n';
	}
	else cout << -1 << '\n';

}