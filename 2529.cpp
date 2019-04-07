#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	char input;
	bool check = false;
	cin >> n;
	vector<char> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		b[i] = input;
	}
	vector<int> n_max(n+1);
	vector<int> n_min(n+1);
	for (int i = 0; i <= n; i++)
	{
		n_max[i] = 9 - i;
		n_min[i] = i;
	}

	do {
		for (int i = 0; i < n; i++)
		{
			if ((b[i] == '<' && n_max[i] < n_max[i + 1]) || (b[i] == '>' && n_max[i] > n_max[i + 1])) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		if (check == true) break;
	} while (prev_permutation(n_max.begin(), n_max.end()));
	check = false;
	do {
		for (int i = 0; i < n; i++)
		{
			if ((b[i] == '<' && n_min[i] < n_min[i + 1]) || (b[i] == '>' && n_min[i] > n_min[i + 1])) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		if (check == true) break;
	} while (next_permutation(n_min.begin(), n_min.end()));

	for (int j : n_max) cout << j;
	cout << '\n';
	for (int j : n_min) cout << j;
	cout << '\n';


	return 0;
}