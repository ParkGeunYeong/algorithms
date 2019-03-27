#include<iostream>
using namespace std;
long long d[101][10];

int go(int n) {
	if (n == 1) {
		for (int i = 1; i <= 9; i++)
		{
			d[1][i] = 1;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long result = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j < 9) d[i][j] += d[i - 1][j + 1];
			if (j > 0) d[i][j] += d[i - 1][j - 1];
			d[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		result += d[n][i];
	}
	result %= 1000000000;
	cout << result;
	return 0;
}