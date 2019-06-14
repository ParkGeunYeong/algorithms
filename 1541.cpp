#include<iostream>
#include<string>
using namespace std;

int main() {
	int ans = 0, tempNum = 0;
	bool minusCase = false;
	string s;
	cin >> s;
	for (char i : s) {
		if (i == '+') {
			ans += tempNum;
			tempNum = 0;
		}
		else if (i == '-') {
			ans += tempNum;
			minusCase = true;
			tempNum = 0;
		}
		else {
			if (minusCase) tempNum = tempNum * 10 - (i - '0');
			else tempNum = tempNum * 10 + (i - '0');
		}
	}
	cout << ans + tempNum;

	return 0;
}