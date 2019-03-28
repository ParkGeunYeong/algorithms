#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;

int main() {
	int n, input;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a.push_back(i);
	}
	do {
		for (int i : a) cout << i << ' ';
		cout << '\n';
	} while(next_permutation(a.begin(), a.end()));

	return 0;
}
