#include<iostream>
using namespace std;
int v[101];
int cache[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	cache[0] = 1; //������ ��ġ�� cache������ k�� ������ ���
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - v[i] >= 0) {
				cache[j] += cache[j - v[i]];
			}
		}
	}
	cout << cache[k] << '\n';

	return 0;
}