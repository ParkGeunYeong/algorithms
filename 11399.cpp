#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	vector<int> time(n);
	for (int i = 0; i < n; i++)
	{
		cin >> time[i];
	}
	sort(time.begin(), time.end());
	for (int i = 0; i < n; i++)
	{
		ans += time[i] * (n - i);
	}
	cout << ans;

	return 0;
}