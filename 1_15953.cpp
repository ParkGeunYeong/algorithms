#include<iostream>
using namespace std;
int money17[21] = { 500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10 };
int money18[31] = { 512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, a, b, result;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		result = 0;
		if (a != 0 && a <= 21) result += money17[a - 1]*10000;
		if (b != 0 && b <= 31) result += money18[b - 1]*10000;
		cout << result << '\n';
	}
	return 0;
}