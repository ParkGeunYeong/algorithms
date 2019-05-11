#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
bool broken[10];

bool possible(int num) {
	while (1) {
		if (broken[num % 10]) return false;
		if (num < 10) return true;
		num /= 10;
	}
}

int main() {
	int n, m, input;
	cin >> n >> m;
	int len = 987654321;
	while (m--) {
		cin >> input;
		broken[input] = true;
	}
	int min = 987654321;
	for (int i = 0; i < 1000000; i++)
	{
		if (possible(i)&& abs(i - n) < min) {
			len = to_string(i).size();
			min = abs(i - n);
			if (min < abs(i + 1 - n)) break;
		}
	}
	if (min + len < abs(n - 100)) cout << min + len << '\n';
	else cout << abs(n - 100) << '\n';


	return 0;
} 