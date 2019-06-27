#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> w(n);
	vector<int> order(n);
	for (int i = 0; i < n; i++)
	{
		order[i] = i;
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			w[i].push_back(input);
		}
	}
	int ans = 987654321;
	do {
		bool zero = false;
		int cost = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int from = order[i];
			int to = order[i + 1];
			if (w[from][to] == 0) {
				zero = true;
				break;
			}
			cost += w[from][to];
		}
		if (zero || w[order[n - 1]][order[0]] == 0) continue;
		cost += w[order[n - 1]][order[0]];
		if (ans > cost) ans = cost;
	} while (next_permutation(order.begin()+1, order.end()));

	cout << ans;

	return 0;
}