#include<iostream>
using namespace std;
int d[1001][10];

int go(int n, int l) {
	if (n == 1) return 1;

	int& ret = d[n][l];
	if (ret > 0) return ret;

	for (int j = 0; j <= 9; j++)
	{
		for (int k = 0; k <= j; k++)
		{
			d[n][j] += go(n - 1,k);
			d[n][j] %= 10007;
		}
	}
	
	return ret;
}

int result(int n) {
	int ret = 0;
	for (int i = 0; i <= 9; i++)
	{
		ret += go(n,i);
	}
	return ret %= 10007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	
	cout << result(n);
	return 0;
}