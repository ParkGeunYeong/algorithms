#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n), d(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	d[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
