#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;

int main() {
	int n, input;
	cin >> n;
	while (n--) {
		cin >> input;
		a.push_back(input);
	}

	if (next_permutation(a.begin(), a.end())) {
		for (int i : a) cout << i << ' ';
	}
	else cout << -1 << '\n';

	return 0;
}
