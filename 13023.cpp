#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> al[2000];
bool check[2000];

bool go(int x,int cnt) {
	if (cnt == 5) return true;
	if (check[x]) return false;
	check[x] = true;
	for (int i : al[x]) {
		if (go(i, cnt + 1)) return true;
	}
	check[x] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin >> v >> e;
	int n1, n2;
	for (int i = 0; i < e; i++) {
		cin >> n1 >> n2;
		al[n1].push_back(n2); al[n2].push_back(n1);
	}
	for (int i = 0; i < v; i++)
	{
		if (go(i,0)) {
			cout << 1 << '\n';
			return 0;
		}
		memset(check, false, sizeof(check));
	}
	cout << 0 << '\n';

	return 0;
}