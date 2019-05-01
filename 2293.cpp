#include<iostream>
#include<cstring>
using namespace std;
int coin[101];
int cache[101][10001];

int go(int n, int k) {
	if (k < 0) return 0;
	if (k == 0) return 1;

	int& ret = cache[n][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = n; i >= 1; i--)
	{
		ret += go(i, k - coin[i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << go(n, k) << "\n";
		
	return 0;
}