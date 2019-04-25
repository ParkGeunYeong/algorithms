#include<iostream>
#include<algorithm>
using namespace std;
int d[1001];
int p[1001];

int go(int n) {
	if (n == 1) return p[1]; //1. 기저사례

	if (d[n] > 0) return d[n]; //2. 메모체크

	for (int i = 1; i <= n; i++) //3. 계산
	{
		d[n] = max(d[n], p[i] + go(n-i));
	}
	
	return d[n]; //4.결과 반환
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, temp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	cout << go(n);
	return 0;
} 