#include<iostream>
#include<cstring>
using namespace std;
int coin[101];
int cache[10001];

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
	int result = 0;
	cache[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			cache[j] += cache[j - coin[i]];
		}
	}

	cout << cache[k] << '\n';
		
	return 0;
}