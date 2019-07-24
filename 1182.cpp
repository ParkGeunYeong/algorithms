#include <iostream>
using namespace std;
int nums[20];

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> nums[i];

	int cnt = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) {
				sum += nums[j];
			}
		}
		if (sum == s) cnt += 1;
	}

	cout << cnt;

	return 0;
}
