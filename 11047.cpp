#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	for (int i = n-1; i >= 0; i--)
	{
		ans += k / coin[i];
		k = k % coin[i];
	}

	cout << ans;

	return 0;
}