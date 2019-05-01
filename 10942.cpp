#include<iostream>
#include<cstring>
using namespace std;
int number[2001];
int cache[2001][2001];

int go(int s, int e) {
	if (s == e) return 1;
	if (s + 1 == e)
		if (number[s] == number[e]) return 1;
		else return 0;

	if (cache[s][e] != -1) return cache[s][e];

	if (number[s] != number[e]) return cache[s][e] = 0;
	else return cache[s][e] = go(s + 1, e - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}
	memset(cache, -1, sizeof(cache));
	int m;
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << go(s, e) << '\n';
	}
	return 0;
}