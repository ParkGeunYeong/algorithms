#include<iostream>
using namespace std;
int d[1001];

int go(int n) {
	if (n <= 2) { // ���� �� �ʱ�ȭ? ���ϱ�
		return n;
	}
	if (d[n] > 0) { // �̹� ������ ��
		return d[n];
	}
	d[n] = (go(n - 1) + go(n - 2)) % 10007; //���� ������ �ʾ����� ���
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