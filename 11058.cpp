#include<iostream>
#include<algorithm>
using namespace std;
long long cache[101];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cache[i] = i;
		for (int j = 3; j <= i; j++)
		{
			cache[i] = max(cache[i], max(cache[i - 1] + 1, cache[i - j] * (j - 1)));
		}
	}
	cout << cache[n] << '\n';
	return 0;
}