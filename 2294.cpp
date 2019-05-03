#include<iostream>
using namespace std;

int cache[10001];
int v[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i <= k; i++)
	{
		cache[i] = k + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - v[i] == 0) cache[j] = 1;
			if (j - v[i] > 0 && cache[j] > cache[j - v[i]] + 1) cache[j] = cache[j - v[i]] + 1;
		}
	}
	if (cache[k] == k + 1) cout << -1 << '\n';
	else cout << cache[k] << '\n';
}