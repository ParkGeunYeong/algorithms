#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int len = to_string(n).size();
	int ans = 0;
	for (int i = 0; i < len - 1; i++)
	{
		ans += (i + 1) * (pow(10, i + 1) - pow(10, i));
	}
	ans += len * (n - pow(10, len - 1) + 1);

	cout << ans << '\n';
	return 0;
}