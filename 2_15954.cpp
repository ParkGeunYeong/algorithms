#include<iostream>
#include<math.h>
using namespace std;
int n, k, p[500];

long double go(int s, int e) {
	long double m = 0, b = 0, f;
	for (int i = s; i <= e; i++)
	{
		m += p[i];
	}
	m = m / (long double)(e - s + 1);
	for (int i = s; i <= e; i++)
	{
		b += pow(p[i] - m, 2);
	}
	b = b / (long double)(e - s + 1);
	f = sqrt(b);
	return f;
}


int main() {
	cin >> n >> k;
	long double result , temp;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	result = go(0, k - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = k - 1; i + j < n; j++)
		{
			temp = go(i, i + j);
			if (temp < result) result = temp;
		}
	}
	printf("%5.11llf\n", result);
}