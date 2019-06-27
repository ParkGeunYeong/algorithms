#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int max = 0;
	vector<string> input(n);
	vector<char> alpa;
	vector<int> num;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		for (char c : input[i]) alpa.push_back(c);
	}
	sort(alpa.begin(), alpa.end());
	alpa.erase(unique(alpa.begin(), alpa.end()), alpa.end());
	for (int i = 0; i < alpa.size(); i++)
	{
		num.push_back(9 - i);
	}
	sort(num.begin(), num.end());
	//for (char c : alpa) cout << c << ' ';
	//cout << '\n';
	//for (int c : num) cout << c << ' ';
	//cout << '\n';
	do {
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			for (char c : input[i]) {
				for (int j = 0; j < alpa.size(); j++)
				{
					if (c == alpa[j]) {
						temp = temp * 10 + num[j];
						break;
					}
				}
			}
			sum += temp;
		}
		if (sum > max) max = sum;
	} while (next_permutation(num.begin(), num.end()));

	cout << max;

	return 0;
}