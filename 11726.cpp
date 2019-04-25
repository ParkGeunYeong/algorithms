#include<iostream>
using namespace std;
int d[1001];

int go(int n) {
	if (n <= 2) { // 시작 값 초기화? 구하기
		return n;
	}
	if (d[n] > 0) { // 이미 구했을 때
		return d[n];
	}
	d[n] = (go(n - 1) + go(n - 2)) % 10007; //값을 구하지 않았으면 계산
	return d[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << go(n);
	return 0;
}