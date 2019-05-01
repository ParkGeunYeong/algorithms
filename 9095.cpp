#include<iostream>
using namespace std;
int d[1001];

int go(int n) {
	if (n <= 2) {
		return n <= 1 ? 1 : 2;
	}

	if (d[n] > 0) return d[n];

	d[n] = go(n - 1) + go(n - 2) + go(n - 3);

	return d[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << go(n) << "\n";
	}
	return 0;
}