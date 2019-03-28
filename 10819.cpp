#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;

int main() {
	int n, input, sum = 0, max = -987654321;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		a.push_back(input);
	}
	sort(a.begin(),a.end());
	do {
		sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			sum += abs(a[i] - a[i + 1]);
		}
		if (max < sum) max = sum;
	} while (next_permutation(a.begin(), a.end()));
	cout << max << '\n';
	return 0;
}
