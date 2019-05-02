#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long cache[501][501];
int chapter[501];

long long go(int i, int j) {
	if(i == j) return 0;

	long long& ret = cache[i][j];
	if (ret != -1)return ret;

	ret = 987654321;
	int sum = 0;
	for (int s = i; s <= j; s++) {
		sum += chapter[s];
	}

	for (int n = i; n < j; n++)
	{
		ret = min(ret, go(i,n) + go(n+1, j) + sum);
	}
	return ret;
}

int main() {
	int t, result = 0;
	cin >> t;
	while (t--) {
		memset(chapter, -1, sizeof(chapter));
		memset(cache, -1, sizeof(cache));
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> chapter[i];
		}
		cout << go(1, k) << '\n';
	}
	return 0;
}