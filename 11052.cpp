#include<iostream>
#include<algorithm>
using namespace std;
int d[1001];
int p[1001];

int go(int n) {
	if (n == 1) return p[1]; //1. �������

	if (d[n] > 0) return d[n]; //2. �޸�üũ

	for (int i = 1; i <= n; i++) //3. ���
	{
		d[n] = max(d[n], p[i] + go(n-i));
	}
	
	return d[n]; //4.��� ��ȯ
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