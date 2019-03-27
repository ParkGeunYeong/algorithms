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
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (d[i] < d[j]+1 && a[j] < a[i]) { //max를 찾는 과정, 앞보다 큰 수인지 판별
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
