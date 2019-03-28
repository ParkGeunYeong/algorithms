#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
vector<bool> b;

int main() {
	int n;
	char input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		b.push_back(input == '<' ? true : false);
	}
	vector<int> n_max(n + 1);
	vector<int> n_min(n + 1);
	for (int i = 0; i <= n; i++)
	{
		n_max.push_back(9 - n + i);
		n_min.push_back(i);
	}

	int sum, int max = -1;
	do {
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if ((b[i] && n_max[i] < n_max[i + 1]) || (!b[i] && n_max[i] > n_max[i + 1])) {
				sum += n_max[i]*pow(10, n - i + 1);
			}
			else {
				break;
			}
			if (max < sum) max = sum;
		}
	} while (next_permutation(n_max.begin(), n_max.end()));
	cout << max << '\n';

	int sum, int min = 11;
	do {
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if ((b[i] && n_min[i] < n_min[i + 1]) || (!b[i] && n_min[i] > n_min[i + 1])) {
				sum += n_min[i] * pow(10, n - i);
			}
			else {
				break;
			}
			if (min > sum) min = sum;
		}
	} while (next_permutation(n_min.begin(), n_min.end()));
	if (min < pow(10, n)) cout << 0;
	cout << min << '\n';

	return 0;
}
