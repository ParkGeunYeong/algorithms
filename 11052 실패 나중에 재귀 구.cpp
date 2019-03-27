#include<iostream>
using namespace std;
int d[1001];
int p[1001];

int go(int n,int j) {
	d[n] = go(p[n-j],j-1)
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, temp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			temp = d[i - j] + p[j];
			d[i] = temp > d[i] ? temp : d[i];
		}
	}
	cout << d[n];
	return 0;
} 