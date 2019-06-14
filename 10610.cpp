#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int main() {
	string s;
	bool zero = false;
	int num = 0;
	cin >> s;
	for (char i : s) {
		if (!zero && i - '0' == 0) zero = true;
		else num += (i - '0');
	}
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	if (num % 3 == 0 && zero) cout << s;
	else cout << -1;
}